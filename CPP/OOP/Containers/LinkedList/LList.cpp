#pragma once
#include "LList.h"


template<typename T>
LList<T>::LList()
{
    first = nullptr;
}

template<typename T>
LList<T>::LList(const LList<T>& others)
{
    if(others.empty())
    {
        this->first = nullptr;
        return;
    }
    Box<T>* current = others.first;
    Box<T>* thisCurrent = new Box<T>(current->data, nullptr);
    first = thisCurrent;

    while(current->next != nullptr)
    {
        current = current->next;
        thisCurrent->next = new Box<T>(current->data, nullptr);
        thisCurrent = thisCurrent->next;
    }
}

template<typename T>
LList<T>& LList<T>::operator=(const LList<T>& others)
{
    if(this != &others)
    {
        delete this;
        if(others.empty())
        {
            this->first = nullptr;
        }
        Box<T>* current = others.first;
        Box<T>* thisCurrent = new Box<T>(current->data, nullptr);
        first = thisCurrent;
    
        while(current->next != nullptr)
        {
            current = current->next;
            thisCurrent->next = new Box<T>(current->data, nullptr);
            thisCurrent = thisCurrent->next;
        }

    }
    return *this;
}

template<typename T>
LList<T>::~LList()
{
    clear();
}

template<typename T>
void LList<T>::print()
{
    Box<T>* current = first;
    while(current != nullptr)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

template<typename T>
void LList<T>::push(const T& newElem)
{
    first = new Box<T>(newElem, first);
}

template<typename T>
void LList<T>::push_back(const T& newElem)
{
    if(first == nullptr)
    {
        first = new Box<T>(newElem, nullptr);
        return;
    }

    Box<T>* current = first;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Box<T>(newElem, nullptr);
}

template<typename T>
void LList<T>::push_back_box(Box<T>& other)
{
    if(first == nullptr)
    {
        *first = other;
        return;
    }
    Box<T>* current = first;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    *(current->next) = other;
}

template<typename T>
void LList<T>::pop()
{
    Box<T>* toDelete = first;
    first = first->next;
    delete[] toDelete; 
}

template<typename T>
void LList<T>::pop_back() 
{
    Box<T>* current = first;
    while(current->next->next != nullptr)
    {
        current = current->next;
    }

    delete[] current->next;
    current->next = nullptr;
}

template<typename T>
void LList<T>::clear()
{
    while(!this->empty())
    {
        Box<T>* toDelete = first;
        first = first->next;
        delete[] toDelete;
    }
}

template<typename T>
void LList<T>::insertAfter(const T& x , int i) 
{
    //1 2 2.5 3
    if(i == 0)
    {
        push(x);
    }
    
    Box<T>*current = first;
    while(current != nullptr && i > 0)
    {
        --i;
        current = current->next;
      //1->2->3
    }

    if(current == nullptr)
    {
        std::cout << "Error -> way after the last element of the list";
    }
    else
    {
        Box<T>*newBox = new Box<T>(x,current->next);
        current->next = newBox;
    }

}
   

template<typename T>
void LList<T>::deleteAt(int i)
{
    if( i == 0)
    {
        return pop();
    }
    --i;
    Box<T>* previous = first;
    while(previous != nullptr && i > 0)
    {
        --i;
        previous = previous->next;
    }
    if(previous == nullptr || previous->next == nullptr)
    {
        std::cout << "Error";
    }
    else
    {
        Box<T>* toBeDeleted = previous->next;
        previous->next = toBeDeleted->next;
        delete toBeDeleted;
    }

}

template<typename T>
int LList<T>::size() const
{
    Box<T>* current = first;
    size_t cnt = 0;
    while(current != nullptr)
    {
        current = current->next;
        cnt++;
    }

    return cnt;
}

template<typename T>
const Box<T>* LList<T>::front() const
{
    return first;    
}

template<typename T>
bool LList<T>::empty() const
{
    return first == nullptr;
}

template<typename T>
LList<T>& LList<T>::removeDublicates()
{
    Box<T>* current = this->first;
    Box<T>* next1;
    size_t indexNext, currIndex = 0;
    bool flag;

    while (current->next != nullptr)
    {
        flag = false;
        next1 = current->next;
        indexNext = currIndex + 1;
        while (next1 != nullptr)
        {
            if (next1->data == current->data)
            {
                next1 = next1->next;
                this->deleteAt(indexNext);
                flag = true;
                continue;
            }
            next1 = next1->next;
            indexNext++;
        }
        if(flag)
        {
            current = current->next;
            this->deleteAt(currIndex);
        }
        else
        {
            current = current->next;
            currIndex++;
        }
    }
}
