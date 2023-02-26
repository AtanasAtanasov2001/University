#include <exception>
#include <cstddef>
#include <cassert>
#pragma once
//lifo
class LinkedStack
{
public:
    LinkedStack();
    LinkedStack(const LinkedStack& stack);
    ~LinkedStack();
    LinkedStack& operator= (const LinkedStack& rhs);

    void push(int elem);
    int pop();
    const int& top() const;
    bool isEmpty() const;
    
private:
    struct node
    {
        int data;
        node* next;

        node(int d, node* n = nullptr)
            : data(d)
            , next(n)
        {}
    } *tos;
private:
    void clear();
    void copy(const node* top);
};

#include "linkedStack_mine.inl"