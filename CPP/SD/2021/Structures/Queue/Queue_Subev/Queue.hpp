#include "Double_LL.hpp"


template <typename T>
class Queue
{
private:
    DoubleLinkedList<T> data;
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
        data.pop_front();
    }
    //O(n) -> O(1)
    size_t size() {
        return this->data.getSize();
    }
};


