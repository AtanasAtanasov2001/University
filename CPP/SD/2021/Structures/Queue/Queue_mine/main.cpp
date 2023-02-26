#include <iostream>
#include "linkedQueue_M.h"
int main() {

    LinkedQueue<int> l1;
    std::cout << std::boolalpha << l1.isEmpty() << std::endl;
    
    l1.enqueue(1);
    l1.enqueue(2);
    l1.enqueue(3);
    l1.enqueue(4);
    l1.enqueue(5);
    l1.enqueue(6);
    l1.enqueue(7);
    std::cout << std::boolalpha << l1.isEmpty() << std::endl;
    std::cout << l1.Size();

    LinkedQueue<int> l2(l1);
    while (!l2.isEmpty()) {
      std::cout << l2.dequeue() << std::endl;
    }
    std::cout << l2.Size();
    std::cout << std::boolalpha << l2.isEmpty() << std::endl;
    std::cout << std::boolalpha << l1.isEmpty() << std::endl;

    LinkedQueue<int> l3 = l1;
    std::cout << std::boolalpha << l3.isEmpty() << std::endl;
    std::cout << l3.dequeue() << std::endl;

  return 0;
}