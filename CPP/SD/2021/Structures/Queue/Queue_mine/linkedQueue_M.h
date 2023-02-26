#include <cassert>
#include <cstddef>
#include <exception>

template <typename DataType>
class LinkedQueue 
{
public:
    LinkedQueue(): begin(nullptr), end(nullptr) {}
   
    LinkedQueue(const LinkedQueue<DataType>& other);

    LinkedQueue<DataType>& operator=(const LinkedQueue<DataType>& other);
    ~LinkedQueue();

    void enqueue(const DataType& data);
    DataType dequeue();
    const DataType& first() const;
    bool isEmpty() const ;
    int Size();
    bool isFull() const {return false;}

private:
    struct node
    {
        DataType data;
        node* next;
        node(const DataType& data, node* n = nullptr)
            : data(data), next(n) {}
    } *begin, *end;
    int size = 0;

private:
    void clear();
    void copy(const node* start);
};

template<typename T>
void LinkedQueue<T>::copy(const node* start)
{
    assert(begin == nullptr && isEmpty());
    
    while(start) {
        enqueue(start->data);
        start = start->next;
    }
}

template <typename T>
void LinkedQueue<T>::clear() {
  while (!isEmpty()) {
      node* temp = begin;
      begin = begin->next;
      delete temp;
  }
}

template<typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}
template<typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& other)
{
    if(this != &other)
    {
        clear();
        copy(other.begin);
    }
    return *this;
}

template<typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other) {
    begin = nullptr;
    copy(other.begin);
}


template<typename T>
void LinkedQueue<T>::enqueue(const T& data) {
    node* helper = new node(data);
    if(isEmpty())
    {
        begin = helper;
    }
    else {
        end->next = helper;
    }
    end = helper;
    size++;
}

template<typename T>
T LinkedQueue<T>::dequeue() {
    if(!isEmpty()) {
        T temp_value = begin->data;
        node* toDelete = begin;
        begin = begin->next;
        delete[] toDelete;
        size--;
        return temp_value;
    }
    //throw std::invalid_argument("The queue is empty");

}

template<typename T>
const T& LinkedQueue<T>::first() const {
    if(!isEmpty()) {
        return begin->data;
    }
    throw std::invalid_argument("the queue is empty");
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const{
  return begin == nullptr;
}

template<typename T>
int LinkedQueue<T>::Size() {
    return this->size;
    
}

