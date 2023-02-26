#include <iostream>

//================================================
//===================TASK1========================
template <typename T>
struct TypedBuffer
{
    T* arr;
    size_t size;

    TypedBuffer()
    {
        arr = nullptr;
        size = 0;
    }
    ~TypedBuffer()
    {
        delete[] arr;
        size = 0;
    }
};
template <typename T>
TypedBuffer<T> create(size_t n , T k)
{
    TypedBuffer<T> m;
    m.size = n;
    m.arr = new T[n];
    for (size_t i = 0; i < n; i++)
    {
        m.arr[i] = k;
    }
    return m;
}
template <typename T>
TypedBuffer<T> *append(TypedBuffer<T>& a, const TypedBuffer<T>& b)
{
    T *newArr = a.arr;
    a.arr = new T[a.size + b.size];

    for (size_t i = 0; i < a.size; i++)
    {
        a.arr[i] = newArr[i];
        // std::cout << a.arr[i] << "!!";
    }
    for (size_t i = 0; i < b.size; i++)
    {
        a.arr[a.size + i] = b.arr[i];
    }
    a.size += b.size;
    delete[] newArr;
    
    return &a;
}
template <typename T>
TypedBuffer<T> *concat(TypedBuffer<T> &a, TypedBuffer<T> &b)
{
    TypedBuffer<T> *newbuff = append(a,b);
    return newbuff;
}

template<typename T>
bool containsElement( TypedBuffer<T> c, T elem) {
    for (int i = 0; i < c.size; ++i) {
        if (c.arr[i] == elem)
            return true;
    }
    return false;
}
template <typename T>
TypedBuffer<T> unioN(TypedBuffer<T> &a, TypedBuffer<T> &b)
{
    int position = 0;
    TypedBuffer<T> newBuff = create((a.size + b.size), 0);
    for (size_t i = 0; i < a.size; i++)
    {
        if(!containsElement(newBuff,a.arr[i]))
        {
            newBuff.arr[position++] = a.arr[i];
        }
    }
    for (size_t i = 0; i < b.size; i++)
    {
        if(!containsElement(newBuff,b.arr[i]))
        {
            newBuff.arr[position++] = b.arr[i];
        }
    }
    newBuff.size = position;
    return newBuff;
}
template <typename T>
void printBuffer(TypedBuffer<T> k)
    {
        for (size_t i = 0; i < k.size; i++)
        {
            std::cout << k.arr[i] << " ";
        }
        std::cout << std::endl;
        
    }

//================================================
//===================TASK2========================

class SumAvgCalculator
{
    private:
    int *sequence;
    size_t size;

    public:
    SumAvgCalculator()
    {
        size = 0;
        sequence = nullptr;
    };
    SumAvgCalculator(int num)
    {
        size = 1;
        sequence = new int[1];
        sequence[0] = num;
    }
    SumAvgCalculator(SumAvgCalculator &other)
    {
        this->size = other.size;
        for (size_t i = 0; i < other.size; i++)
        {
            this->sequence[i] = other.sequence[i];
        }
        
    }
    SumAvgCalculator& operator=(SumAvgCalculator &other)
    {
        if (this != &other)
        {
            this->size = other.size;
            for (size_t i = 0; i < other.size; i++)
            {
                this->sequence[i] = other.sequence[i];
            }   
        }   
    }
    ~SumAvgCalculator()
    {
        this->size = 0;
        delete[] this->sequence;
    }

    double sum()
    {
        double sum = 0;
        for (size_t i = 0; i < this->size; i++)
        {
            sum += this->sequence[i];
        }
        return sum;
    }
    void add(int newnum)
    {
        int* old = this->sequence;
        this->sequence = new int[this->size + 1];

        for (size_t i = 0; i < this->size; i++)
        {
            this->sequence[i] = old[i];
        }
        this->sequence[size] = newnum; 
        this->size += 1;
        delete[] old;

    }
    void sub(int negnum)
    {
        add(negnum * -1);
    }
    int num()
    {
        return size;
    }
    double average()
    {
        return (sum()/size);
    }
    SumAvgCalculator& operator+(SumAvgCalculator &other)
    {
        SumAvgCalculator* new_cal = this;
        *new_cal += other;
        return *new_cal;  
    }
    SumAvgCalculator& operator+=(SumAvgCalculator &other)
    {
        for (size_t i = 0; i < other.size; i++)
            {
                this->add(other.sequence[i]);
            }
        return *this;
    }

};
int main()
{
    // TypedBuffer<int> k = create(3,4);
    // TypedBuffer<int> m = create(4,2);
    // printBuffer(k);
    // printBuffer(m);
    // // append(k,m);
    // //printBuffer(k);
    // // TypedBuffer<int> *m1 = concat(k,m);
    // // printBuffer(*m1);
    // TypedBuffer<int> union_buffs = unioN(k,m);
    // printBuffer(union_buffs);
 
    SumAvgCalculator seq1(10); 
    seq1.add(10);
    seq1.add(5); 
    seq1.sub(15); 
    std::cout << seq1.sum(); //->10 (10+10+5-15)    
    
}