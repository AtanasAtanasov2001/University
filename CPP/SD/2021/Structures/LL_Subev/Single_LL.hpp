#include <cstddef>
#include <exception>
#include <cassert>


template<typename T>
class Node {
    private: 
        T data;
        Node* next;
    public:
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}

        T getData() const { 
            return data;
        }

        Node* getNext() {
            return this->next;
        }
        
        void setData(const T& data) {
            this->data = data;
        }

        void setNext(Node* next) {
            this->next = next;
        }
};

template<typename T>
class SingleLinkedList
{
    public:
        Node<T> *head; 
        Node<T> *tail;
    public: 

        SingleLinkedList() : head(nullptr), tail(nullptr) {}
        //TODO 
        //copy const, operator=, destructor, move semantics
        SingleLinkedList(const SingleLinkedList& other) {
            this->copy(other.head);
        }

        SingleLinkedList& operator=(const SingleLinkedList& other) {

            if(this != &other) {
                this->clear();
                this->copy(other.head);
            }
            return *this;
        }

        ~SingleLinkedList() {
            this->clear();
        }

        // const T& head() const {
        //     return head.getData();
        // }

        bool isEmpty() {
            return head == nullptr;
        }

        void push_front(const T& value) {
            bool isEmptyCheck = isEmpty();
            Node<T> *tempNode = new Node<T>(value, head );
            head = tempNode;
            if(isEmptyCheck) {
                tail = head;
            }
        }

        void push_back(const T& value) {
            if(head == nullptr) {
                push_front(value);
                return;
            }

            // Node<T> *currentNode = head;
            // while(currentNode->getNext() != nullptr) {
            //     currentNode = currentNode->getNext();
            // }

            // Node<T> *tempNode = new Node<T>(value);
            // currentNode->setNext = tempNode; 
            Node<T> * tempNode = new Node<T>(value);
            tail->setNext(tempNode);
            tail = tempNode;

        }

        void pop_front() {
            if(head == nullptr) {
                // throw std::runtime_error("cannot pop front from an empty list");
            } 
            
            bool check = head==tail;
            Node<T> *oldHead = head;
            head = head->getNext();
            delete oldHead;

            if(check) {
                tail = nullptr;
            }
        }

        void pop_back() {
            if(head == nullptr) {
                // throw std:runtime_error("cannot pop bavc from an empty list");
            }

            bool check = head==tail;
            Node<T> *currentNode = head;
            Node<T> *next = currentNode->getNext();
            while (next != nullptr && (next->getNext != nullptr)) {
                currentNode = next;
                next = currentNode->getNext();
            }

            if(next == nullptr) {
                delete currentNode;
                head = nullptr;
            }else {
                currentNode->setNext(nullptr);
                delete next;
            }

            if(check) {
                tail = nullptr;
            }
        }

    
    private:
        void copy(Node<T> &from) {
            assert(this->isEmpty());

            while(from) {
                this->push_back(from->getData());
                from->setNext(from->getNext());
            }
        }

        void clear() {
            assert(!this->isEmpty());

            while(this->head) {
                this->pop_front();
            }
        }
        
        // void move(Node<T> &from) {
        //     copy(from);
            
        // }
};