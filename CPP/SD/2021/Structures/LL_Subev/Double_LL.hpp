#include <exception>

template<typename T>
class Node {
    private: 
        T data;
        Node* next;
        Node* previous;
    public:
        Node(cosnt T& data, Node* next = nullptr, Node *previous = nullptr) : data(data), next(next), previous(previous) {}

        T getData() const { 
            return data;
        }

        Node* getNext() {
            return this->next;
        }
        
        Node* getPrevious() {
            return this->previous;
        }

        void setData(const T& data) {
            this->data = data;
        }

        void setNext(Node* next) {
            this->next = next;
        }

        void setPrevious(Node* previous) {
            this->previous = previous;
        }
};



template<typename T>
class DoubleLinkedList {
    private:
        Node<T> *head{nullptr};
        Node<T> *tail{nullptr};// -> for the optimised case
        size_t size{0};
    public:
        DoubleLinkedList() = default;
        //TODO 
        //copy const, operator=, destructor, move semantics
        DoubleLinkedList& operator=(const DoubleLinkedList<T> &other) {
            if(this != &other) {
                this->clear();
                this->copy(other.head);
            }
            
            return *this;
        }

        DoubleLinkedList(const DoubleLinkedList<T> &other) {
            this->copy(other.head)
        }

        ~DoubleLinkedList() {
            this->clear();
        }

        const size_t getSize(){
            return this->size;
        }

        const T& head() const {
            return head->getData();
        }

        bool isEmpty() {
            return head == nullptr;
        }

        void push_front(const T& value) {
            Node<T> *tempNode = new Node(value, head);
            if(!isEmpty()) {
                head->setPrevious(tempNode);
            } 
            else {
                tail = tempNode;
            }
            head = tempNode;
            size++;
        }
        // O(n) -> O(1)
        void push_back(const T& value) {
            if(!isEmpty()) {
                push_front(value);
                return;
            }
            tail->setNext(new Node<T>(value, nullptr, tail));
            tail = tail->getNext();
            size++;
            // Node<T> *currentNode = tail;
            // currentNode->setNext(new Node<T>(value, nullptr, currentNode));
            // tail = currentNode;
        }
        // O(n) -> O(1)
        void pop_back() {
            if(isEmpty()) {
                throw std::runtime_error("cannot pop from an empty Double linked list!");
            }
            Node<T> *toBeDeleted = this->tail;
            this->tail = this->tail->getPrevious();
            delete toBeDeleted;
            size--;
        }

        void pop_front() {
            assert(!this->isEmpty());
            
            Node<T> *toBeDeleted = this->head;
            this->head = this->head->getNext();
            delete toBeDeleted;
            size--;
        }

    private:
        void copy(Node<T> *from) {
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
};