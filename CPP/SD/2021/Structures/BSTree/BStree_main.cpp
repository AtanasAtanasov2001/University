#include "BinarySearchTree.hpp"
#include <iostream>

int main() {
    BSTree b1;
    b1.add(2);
    b1.add(1);
    b1.add(5);
    b1.add(3);
    b1.add(6);
    b1.add(4);
    BSTree b2(b1);
    b1.add(0);
    b1.print();
    // b2.print();
    // BSTree b3 = b1;
    // // b3.print();
    // b1.~BSTree();
    // b1.print();
    // b2.print();

    // b1.search(10);
    // b1.search(3);
    return 0;
}