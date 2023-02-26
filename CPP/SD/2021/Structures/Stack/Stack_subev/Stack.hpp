#include "Single_LL.hpp"

template <typename T>
class Stack
{
    private:
        SingleLinkedList<T> data;
    public:
    bool isEmpty() {
        return data.isEmpty();
    }

    T& peek() {
        return data.head();
    }

    void push(const T& value){
        data.push_back(value);
    }

    void pop_front() {

        if(isEmpty()) {
            throw std::runtime_error("The stack is empty");
        }

        data.pop_front();
    }
    
};