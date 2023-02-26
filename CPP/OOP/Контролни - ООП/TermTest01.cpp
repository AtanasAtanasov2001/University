#include <iostream>
#include "calculator.h";

template <typename T>
struct TypedBuffer
{
    
    size_t size;
    T* dynamicArr;

    public:
    T create(size_t n,T k)
    {
        
        if( n > 0)
        {
            size = n;
            dynamicArr = new T[size];

            for (size_t i = 0; i < size; i++)
            {
                dynamicArr[i] = k;
                std::cout << dynamicArr[i];
            }
        }
    }

    T append(T a, T b)
    {
        // 123
                //=> 123321
        // 321

        a = new T[size]
        for (size_t i = 0; i < a.size; i++)
        {
            a[size+i] = b[i];
        }
    }

    T concat (T a, T b)
    {
        T newarr = new T[size*2]
        for (size_t i = 0; i < newarr.size; i++)
        {
           for (size_t j = 0; j < a.size; j++)
            { 
                newarr[i] = a[i];
            }
            
        }
        append(newarr , b)
    }

};

//task2-------------------------------
class SumAvgCalculator
{
    private:

    int* number;
    size_t size;

    public:
    //Big 4
    SumAvgCalculator(int* a);
    SumAvgCalculator operator=(SumAvgCalculator&);
 

    //metods
    int sum();
    void add(int a);
    void sub(const int a);
    int num();
    double average () ;

    //operators
    SumAvgCalculator operator+(const SumAvgCalculator&) ;
    SumAvgCalculator operator+=(const SumAvgCalculator&) const ;

};

//BIG 4
SumAvgCalculator::SumAvgCalculator(int* n_): number(n_)
{}

SumAvgCalculator SumAvgCalculator :: operator= (SumAvgCalculator& a)
{
    for (size_t i = 0; i < this->size; i++)
    {
       this->number[i] = a.number[i];
    }
    
}

//operator +

int SumAvgCalculator::sum()
{
    return *number;
}

// void SumAvgCalculator::add(int a)
// {
//     for (size_t i = 0; i < size; i++)
//     {
//         this[size] = a;
//     }
    
// }

void SumAvgCalculator::sub(const int a)
{
    add(a);
}

int SumAvgCalculator::num()
{
    size_t counter = 0;
    for (size_t i = 0; i < size; i++)
    {
       if (number[i] % 10 != 0)
        {
            counter++;
        }

        else 
        {
            number[i] / 10;
        }
    }
    
}

double SumAvgCalculator::average()
{
   return  this->sum() / this->num();
}

int main()
{

    TypedBuffer<int> buf1;
    buf1.size = 3;
    std::cout << buf1.create(2,3);
    return 0;

}