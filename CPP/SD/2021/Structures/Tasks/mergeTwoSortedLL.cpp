#include <list>
#include"../LL_Subev/Single_LL.hpp"
#include <iostream>
#include <iterator>

// template<typename T>
// class Node {
//     private: 
//         T data;
//         Node* next;
//     public:
//         Node(const T& data, Node* next = nullptr) : data(data), next(next) {}

//         T getData() const { 
//             return data;
//         }

//         Node* getNext() {
//             return this->next;
//         }
        
//         void setData(const T& data) {
//             this->data = data;
//         }

//         void setNext(Node* next) {
//             this->next = next;
//         }
// };


template<typename T>
Node<T>* mergeLists(Node<T>* head1, Node<T>* head2) {
    if(!head1) return head2;
    if(!head2) return head1;

    Node<T> *currentHead1 = head1;
    Node<T> *currentHead2 = head2;
    Node<T> *newHead, *currentNewHead;
    if(currentHead1->getData() < currentHead2->getData()) {
        newHead = currentHead1;
        currentHead1 = currentHead1->getNext();
    } else {
        newHead = currentHead2;
        currentHead2 = currentHead2->getNext();
    }

    currentNewHead = newHead;
    std::cout << newHead->getData();
    while(currentHead1 != nullptr || currentHead2 != nullptr) {
        std::cout << "vleznah while" << "\n";
        if(currentHead2 == nullptr || (currentHead1 && currentHead1->getData() < currentHead2->getData())) {
            std::cout << "vleznah if" << "\n";
            currentNewHead->setNext(currentHead1);
            currentHead1 = currentHead1->getNext();
        } else {
            std::cout << "vleznah else" << "\n";
            currentNewHead->setNext(currentHead2);
            currentHead2 = currentHead2->getNext();
        }
        currentNewHead = currentNewHead->getNext();
    }
    return newHead;
}

template<typename T>
void print_LList(SingleLinkedList<T> *llist) {
    while(!llist->isEmpty()) {
        std::cout << llist->head->getData()<< " ";
        llist->pop_front();
    }
    std::cout << "\n";
 }

template<typename T>
void print_node(Node<T>* node) {
    while (node != nullptr)
    {
        std::cout << node->getData() << " ";
        node = node->getNext();
    }
    std::cout << "\n";
    
}
int main() {

    SingleLinkedList<int>* llist1 = new SingleLinkedList<int>();

    int llist1_count; 
    std::cin >> llist1_count;
    for (size_t i = 0; i < llist1_count; i++)
    {
        int llist1_member;
        std::cin >> llist1_member;
        llist1->push_back(llist1_member);
    }
    print_LList(llist1);

    SingleLinkedList<int>* llist2 = new SingleLinkedList<int>();

    int llist2_count; 
    std::cin >> llist2_count;
    for (size_t i = 0; i < llist2_count; i++)
    {
        int llist2_member;
        std::cin >> llist2_member;
        llist2->push_back(llist2_member);
    }
    print_LList(llist2);

    Node<int> *llist3 = mergeLists(llist1->head, llist2->head);
    print_node(llist3);
    
}