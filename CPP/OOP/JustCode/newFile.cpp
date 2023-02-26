#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>


template<typename T>
class Set
{   

    public:
    virtual bool member(const T&) = 0;    
    virtual ~Set() = 0;
};

template<typename T>
Set<T> ::~Set(){}
template<typename T>
class Range : public Set<T>
{
    private:
    std::vector<T> members;
    T a,b;
    public:
    Range() = default;
    Range(std::vector<T> members_,T a_, T b_) 
    {
        a = a_;
        b = b_;
        this->members = members_;
    }
    ~Range()
    {
        this->members.~vector();
    }
    bool member(const T& x)
    {
        bool flag = false;
        for (size_t i = 0; i < this->members.size(); i++)
        {
            a <= this->members[i] <= b ? flag = true : flag;
        }
        return flag;
    }

};
template <typename T>
class EvenNumbers : public Set<T>
{
    private:
    std::vector<T> members;
    public:
    EvenNumbers() = default;
    EvenNumbers(std::vector<T> members_) 
    {
        this->members = members_;
    }
    ~EvenNumbers()
    {
        this->members.~vector();
    }
    bool member(const int& x)
    {
        bool flag = false;
        for (size_t i = 0; i < this->members.size(); i++)
        {
            this->members[i] % 2 == 0 ? flag = true : flag;
        }
        return flag;
    }
};


template<typename T>
class ManySets : public Set<T>
{
    private:
    std::vector<Set<T>*> sets;
    public:
    ManySets() = default;
    ManySets(std::vector<Set<T>> sets_) : sets(sets_){}
    ~ManySets()
    {
        this->sets = nullptr;
    }
    void add(const Set<T>& newset)
    {
        this->sets.push_back(newset);
    }
    // friend std::ostream& operator<<(std::ostream& out, const ManySets<T>& toPrint);
    // friend std::istream& operator>>(std::istream& in, ManySets<T>& toRead);
};
// template<typename T>
// std::ostream& operator<<(std::ostream& out,const  ManySets<T> &toPrint)
// {
//     for (size_t i = 0; i < toPrint.sets.size(); i++)
//     {
//         out << toPrint.sets[i] << " ";
//     }
    
// }
// template<typename T>
// std::istream& operator>>(std::istream& in,  ManySets<T> &toRead)
// {
//     for (size_t i = 0; i < toRead.sets.size(); i++)
//     {
//         in >> toRead.sets[i];
//     }
    
// }

template<typename T>
class Container : public Set<T>
{
    private:
        T* elements;
        size_t capacity;
    public:
    Container() = default;
    Container(T* elements_,size_t capacity_)
    {
        this->elements = elements_;
        this->capacity = capacity_;
    }
    ~Container()
    {
        this->elements = nullptr;
        this->capacity = 0;
    }
    Container(const Container<T>& other)
    {
        this->elements = other.elements;
        this->capacity = other.capacity;
    }
    Container& operator=(const Container<T>& other) const
    {
        if(this != &other)
        {
            this->elements = other.elements;
            this->capacity = other.capacity;
        }
        return *this;
    }

    size_t size() const
    {
       return this->capacity;
    }
    bool member(const T& newelem)
    {
        for (size_t i = 0; i < size(); i++)
        {
            this->elements[i] != newelem ? true : false;
        }
        
    }
    void add(const T& newelem)
    {
        Container<T>* temp = new Container<T>[this->capacity + 1];
        temp->elements[capacity] = newelem;
        temp = this;
        delete temp;

    }
    Container<T>& operator+(const Container<T> &other)const
    {
        Container<T> temp;
        temp.size() = this->size() + other.size();
        for (size_t i = 0; i < temp.size() - other.size(); i++)
        {
            temp.add(this->elements[i]);
        }
        for (size_t i = 0; i < temp.size(); i++)
        {
            temp.add(other.elements[i]);
        }
        return temp;        
    }
    void print(std::ostream& out)
    {
        for (size_t i = 0; i < size(); i++)
        {
            out << this->elements[i] << " " << std::endl;
        }
        
    }
    void read(std::istream& in)
    {
        for (size_t i = 0; i < size(); i++)
        {
            in >> this->elements[i];
        }
        
    }
  
};
template<typename T>
bool& operator<=(const  Container<T> &a,const Container<T> &b) 
    {
        for (size_t i = 0; i < (a.size() + b.size()); i++)
        {
            (a.elements[i] <= b.elements[i]) ? true : false;
        }
    }

int main()
{
    // std::vector<int> v1;
    // v1.push_back(1);
    // v1.push_back(2);
    // v1.push_back(3);
    // v1.push_back(4);
    // Range<int> r1(v1, 1,5);
    // std::cout << r1.member(3);
    // EvenNumbers<int> e1(v1);
    int arr[3] = {1,2,3};
    Container<int> c1(arr,3);
    c1.add(4);
    c1.print(std::cout);
    return 0;
    //that is all i could think of..i think i am capable of showing more than this..but it all depends on you :)
    //Greetings :)
}