#include <iostream>
#include "DyamicArray.h"
#pragma once
template<typename T>
inline DynamicArray<T> :: DynamicArray() :data(allocateMemory(0)) ,size(0), capacity(0){
} 

template<typename T>
inline DynamicArray<T> :: DynamicArray(const DynamicArray<T>& other) : 
{
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
        delete this->data;
        this->capacity = other.capacity;
        this->size = other.size;
        this->data = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            this->data[i] = other.data[i];
        } 
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
T& DynamicArray<T> :: operator[](const int& index)
{
    if(index > size || index < 0){
    throw std::out_of_range("invalid index");
    }
    return this->data[index];
}

template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const
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
size_t DynamicArray<T> ::getSize() const
{
    return this->size;
}
//{2,3}
template<typename T>
void DynamicArray<T> :: resize(const size_t newSize)
{
    if(newSize < 0){
    throw std::out_of_range("invalid new size");
    }
    T* resize = allocateMemory(size + newSize);
    //size += newSize ;
    capacity += newSize ;
//    capacity *= 2;
//    T* newData = new T[capacity];

   for (size_t i = 0; i < size; i++)
   {
       resize[i] = this->data[i];
   }

//    delete this->data;
    destructAndDeleteRange(data, data + size);
    this->data = resize;
//  {1,2,3,4} => newsize = -1 -> 4 + (1) = 5-> {1,2,3}
}

template <typename T>
void DynamicArray<T>:: reserve(const size_t& newCapacity)
{
    
    // T* reserve = new T [this->capacity + newCapacity];
    if(newCapacity < 0){
    throw std::out_of_range("invalid new capacity");
    }
    this->capacity += newCapacity;
    T* reserve = allocateMemory(capacity);
    size = newCapacity > 0 ? size : capacity;

    for (size_t i = 0; i < size; i++)
    {
        reserve[i] = data[i];  
    }
    destructAndDeleteRange(data, data + size);
    this->data = reserve;
    
    //{1,2,3,0,0,0}
}

template <typename T>
void DynamicArray<T>::push_back(const T& value)
{
    if (this->capacity == this->size)
    {
        this->resize(1);   
    }
    this->data[size++] = value;
   
}
template <typename T>
void DynamicArray<T> :: pop_back() 
{
    
    if (size > 0) {
        
        size--;
    }
    throw std::logic_error("the size can't be zero");
}
template <typename T>
void DynamicArray<T> ::pop_up()
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
void DynamicArray<T> :: pop_desired(size_t index)
{
    if(size > 0)
    {
        for (size_t i = index; i < this->size-1 ; i++)
        {
           data[i] = data[i+1];
        }
        size--;
    }
    throw std::logic_error("the size can't be zero");
}

template <typename T>
bool DynamicArray<T> :: empty() const
{
    return size == 0;
}

template <typename T>
void DynamicArray<T> :: print()
{
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}