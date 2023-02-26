#include "../LL_Subev/Single_LL.hpp"
#include <iostream>
//removes dublicates from a linked list
template<typename T>
Node<T>* removeDuplicates(Node<T>* llist) {
    SingleLinkedList<int> *temp_list = new SingleLinkedList<T>();
    if(llist) {
        temp_list->push_back(llist->getData());
    }
    llist = llist->getNext();

    while(llist) {
        if(llist->getData() != temp_list->tail->getData()) {
            temp_list->push_back(llist->getData());
        }
        llist = llist->getNext();
    }
    return temp_list->head;
}


template<typename T>
void print(Node<T> *node) {
  while(node)
  {
    std::cout << node->getData() << " ";
    node = node->getNext();
  }
}

int main()
{
    SingleLinkedList<int> *l1 = new SingleLinkedList<int>();
    l1->push_back(1);
    l1->push_back(2);
    l1->push_back(2);
    l1->push_back(3);
    l1->push_back(3);
    l1->push_back(4);
    Node<int> *n = removeDuplicates(l1->head);
    print(n);

    return 0;
}
