//#include <iostream>
#include <cstddef>
#include <exception>
#pragma once
template <typename Type>
class DynamicArray
{
    private:
    Type* data;
    size_t size;
    size_t capacity;

    static Type* allocateMemory(const size_t& capacity_){
        return static_cast<Type*>(operator new(sizeof(Type)*capacity_));
    }

    /*
    Static Cast: This is the simplest type of cast which can be used. It is a compile time cast.It does things like implicit 
    conversions between types (such as int to float, or pointer to void*), and it can also call 
    explicit conversion functions (or implicit ones).
    */

    static void constructRange(Type* begin, Type* end, const Type& fillValue){
        while(begin != end)
        {
            new((void*)begin) Type(fillValue);
            ++begin;
        }
    }

    static void constructRange(Type* begin, Type* end){
        while(begin != end)
        {
            new((void*)begin) Type();
            ++begin;
        }
    }
    // vector<student*> -> {{ivan,19},{ivan,19},{ivan,19},{'',0}}

    static void destructRange(Type* begin, Type* end)
    {
        while(begin != end)
        {
            begin->~Type();
            ++begin;
        }
    }

    static void destructAndDeleteRange(Type* begin, Type*end)
    {
        destructRange(begin,end);
        // end = begin + sizeof(Type) + capacity; 
        operator delete(begin);
    }

    static void Copy(Type* begin, Type* end, Type* destination)
    {
        while (begin <= end)
        {
            new((void*)destination) Type(*begin);
            begin++;
            destination++;
        }
        
    }
    public:

    DynamicArray();
    DynamicArray(const size_t& size);
    DynamicArray(const size_t& size, const Type& value);
    DynamicArray(const DynamicArray<Type>& other);
    DynamicArray<Type>& operator=(const DynamicArray<Type>& other);
    ~DynamicArray();

    const Type& operator[](const int& index) const;
    Type& operator[](const int& index);

    bool operator==(const DynamicArray& other) const;

    size_t getSize() const;
    void reserve(const size_t& newCapacity);
    void resize(const size_t newSize);

    void push_back(const Type& value);
    void pop_back();
    void pop_up();
    void pop_desired(size_t index);
    bool empty()const;
    void print();
    

    private:
    class DYN_Iterator
    {
        private:
        Type* data;
    };

};
template<typename T>
inline DynamicArray<T> :: DynamicArray() : size(0), capacity(1)
{
    this->data = this->allocateMemory(this->capacity);
} 

template <typename T>
inline DynamicArray<T> :: DynamicArray(const size_t& size_) : capacity(size_), size(size_), data(allocateMemory(size_))
{
    constructRange(data, data + size);
}
template <typename T>
inline DynamicArray<T> :: DynamicArray(const size_t &size_, const T& value) : capacity(size_), size(size_), data(allocateMemory(size_))
{
    constructRange(data, data + size, value);
}
template<typename T>
inline DynamicArray<T> :: DynamicArray(const DynamicArray<T>& other) : capacity(other.capacity), size(other.size),
                                                                        data(allocateMemory(other.capacity)) 
{
    //constructRange(other.data,other.data + other.size, other.data);
    this->capacity = other.capacity;
    this->size = other.size;
    this->data = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        this->data[i] = other.data[i];
    }
}
template<typename T>
inline DynamicArray<T>& DynamicArray<T>:: operator=(const DynamicArray<T>& other)
{
    if(this != &other)
    {   
        destructAndDeleteRange(data, data + size);
        this->capacity = other.capacity;
        this->size = other.size;
        this->data = new T[capacity];
       
       Copy(other.data, other.data + other.size, this->data);
    }
    return *this;
}

template <typename T>
inline DynamicArray<T> :: ~DynamicArray()
{
    destructAndDeleteRange(data, data + size);
}
template <typename T>
inline const T& DynamicArray<T> :: operator[](const int& index) const
{
    if(index > size || index < 0){
    throw std::out_of_range("invalid index");
    }
    return this->data[index];
}

template <typename T>
inline T& DynamicArray<T> :: operator[](const int& index)
{
    if(index > size || index < 0){
    throw std::out_of_range("invalid index");
    }
    return this->data[index];
}

template <typename T>
inline bool DynamicArray<T>::operator==(const DynamicArray& other) const
{
    if( this->size == other.size)
    {
        for (size_t i = 0; i < this->size; i++)
        {
            if (this->data[i] != other.data[i])
                return false;
        }
        return true;
    }
    return false;
}
template <typename T>
inline size_t DynamicArray<T> ::getSize() const
{
    return this->size;
}
//{2,3}
template<typename T>
inline void DynamicArray<T> :: resize(const size_t newSize)
{
    if(newSize <= size){

        destructRange(data + newSize, data + size);
        size = newSize;
        return;
    }

    if(newSize >= capacity){
        constructRange(data + size, data + newSize);
        size = newSize;
        capacity = newSize;
        return;
    }

    //{1,2,3,-,-,-}
    //size 3 cap 6
    //newsize = 5

    if (newSize > size && newSize < capacity)
    {
        constructRange(data + size, data + newSize);
        size = newSize;
        return;
    }
        
//     T* resize = allocateMemory(size + newSize);
//     //size += newSize ;
//     capacity += newSize ;
// //    capacity *= 2;
// //    T* newData = new T[capacity];

//    for (size_t i = 0; i < size; i++)
//    {
//        resize[i] = this->data[i];
//    }

// //    delete this->data;
//     destructAndDeleteRange(data, data + size);
//     this->data = resize;
// //  {1,2,3,4} => 5 newsize = 7 {1,2,3,4,0,0,0}
}

template <typename T>
inline void DynamicArray<T>:: reserve(const size_t& newCapacity)
{
    // {1,2,3}
    // newcap 5
    // {1,2,3,-,-}
    // cap 5
    // size 5
    // T* reserve = new T [this->capacity + newCapacity];
    if(newCapacity > capacity){
        T* newData = allocateMemory(newCapacity);
        Copy(data,data + size, newData);
        destructAndDeleteRange(data, data + size);
        data = newData;
        capacity = newCapacity;
        //size = newCapacity;

    }
    // }
    // this->capacity += newCapacity;
    // T* reserve = allocateMemory(capacity);
    // size = newCapacity > 0 ? size : capacity;

    // for (size_t i = 0; i < size; i++)
    // {
    //     reserve[i] = data[i];  
    // }
    // destructAndDeleteRange(data, data + size);
    // this->data = reserve;
    
    //{1,2,3,0,0,0}
}

template <typename T>
inline void DynamicArray<T>::push_back(const T& value)
{
    if (this->capacity == this->size)
    {
        this->reserve(capacity * 2);   
    }
    this->data[size++] = value;
   
}
template <typename T>
inline void DynamicArray<T> :: pop_back() 
{
    
    if (size > 0) {
        
        size--;
    }
    throw std::logic_error("the size can't be zero");
}
template <typename T>
inline void DynamicArray<T> ::pop_up()
{
    // if (size > 0) {
    //    data = &data[1]; ---- => fun fact it works :D
    //    size--;
    // }
    // //{1,2,3} -> pop_up -> {2,2,3}
    // //   ^
    // //   | 
    // //  data+1 = 0xadsfa+1+1+1
    // //0xadsfa -> 1 ; 0xadsfa+1 -> 2
    // //data -> 0xadsfa+1

    if (size > 0)
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
    else{
    throw std::logic_error("the size can't be zero");
    }
}

template<typename T>
inline void DynamicArray<T> :: pop_desired(size_t index)
{
    if(size > 0)
    {
        for (size_t i = index; i < this->size-1 ; i++)
        {
           data[i] = data[i+1];
        }
        size--;
    }
    else{
        throw std::logic_error("the size can't be zero");
    }
    
}

template <typename T>
inline bool DynamicArray<T> :: empty() const
{
    return size == 0;
}

template <typename T>
inline void DynamicArray<T> :: print()
{
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}