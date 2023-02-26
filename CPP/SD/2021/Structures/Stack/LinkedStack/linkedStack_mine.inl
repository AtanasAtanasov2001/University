
#include "linkedStack_mine.h"

inline void LinkedStack::copy(const node* top) {
    assert(tos == nullptr);

    if(top) {
        tos = new node(top->data);
        top = top->next;

        node* prev = tos;

        while (top != nullptr) {
            prev->next = new node(top->data);
            prev = prev->next;
            top = top->next;
        }
    }
}


inline LinkedStack::LinkedStack() : tos(nullptr) {}

inline LinkedStack::~LinkedStack() {
    clear();
}

inline LinkedStack :: LinkedStack(const LinkedStack& stack) : tos(nullptr) {
    copy(stack.tos);
}

inline LinkedStack& LinkedStack ::operator= (const LinkedStack& other)
{
    if(this != &other)
    {
        clear();
        copy(other.tos);
    }
    return *this;
}

inline const int& LinkedStack::top() const {
    if (this->isEmpty()) {
        throw std::invalid_argument("Stack is empty." ); 
    }
    return this->tos->data;
}

inline void LinkedStack::push(int elem) {
    tos = new node(elem, tos);
}

inline int LinkedStack::pop()
{
    int value = top();
    node* next = tos;
    tos = tos->next;
    delete next;
    return value;
}

inline void LinkedStack::clear() {
    while (!this->isEmpty()) {
        this->pop();
    }
}

inline bool LinkedStack::isEmpty() const {
    return this->tos == nullptr;
}