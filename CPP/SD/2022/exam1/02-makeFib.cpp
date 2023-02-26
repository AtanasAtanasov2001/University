// #define DOCTEST_CONFIG_IMPLEMENT
// #include "doctest.h"
#include <iostream>

template <typename T>
struct box {T data; box *next;};

/*Поставете тук реализация на функцията makeFib*/
template<typename T>
void makeFib(box<T>* first){

    if(first == nullptr || first->next == nullptr){
        return;
    }

    box<T>* firstElement = first;
    box<T>* secondElement = firstElement->next;
    box<T>* thirdElement = secondElement->next;

    while (thirdElement != nullptr){
        if((firstElement->data + secondElement->data) != thirdElement->data){

            std::cout << "First ->"<< firstElement->data << " \n";
            std::cout <<  "second ->"<<secondElement->data << " \n";
            std::cout <<  "third ->"<<thirdElement->data << " \n";

            firstElement = firstElement;
            secondElement = secondElement;
            secondElement->next = thirdElement->next;
            box<T>* toDelete = thirdElement;
            thirdElement = thirdElement->next;
            delete[] toDelete;
        } else {
            firstElement = secondElement;
            secondElement = thirdElement;
            thirdElement = thirdElement->next;
        }
    }
    
}
template<typename T>
void printList(box<T>* head){
    if(head == nullptr){
        std::cout << "Empty list -> null \n";
    }
    while (head != nullptr){
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
    
}
// TEST_CASE("makeFib basic")
// {
//     box<int> *l1 = new box<int>{1,
//                          new box<int>{1,
//                              new box<int>{2,
//                                  new box<int>{,
//                                       new box<int>{,
//                                           new box<int>{3,
//                                               new box<int>{5,
//                                                   new box<int>{9,nullptr}}}}}}}};
//     makeFib(l1);
//     int expected[] = {1,1,2,3,5};
//     for (int x: expected)
//     {
//         CHECK(x==l1->data);
//         l1=l1->next;
//     }

// }

// TEST_CASE("makeFib edges")
// {
//     box<int> *l2 = new box<int>{1,nullptr};
//     CHECK_NOTHROW(makeFib(l2));
//     CHECK(l2->data == 1);

//     box<int> *l3 = new box<int>{1,new box<int>{2,nullptr}};
//     CHECK_NOTHROW(makeFib(l3));
//     CHECK(l3->next->data == 2);

//     CHECK_NOTHROW(makeFib<int>(nullptr));
// }

int main()
{
    // std::cout << "Three";
    box<int> *l1 = new box<int>{1,
                     new box<int>{1,
                         new box<int>{2,
                             new box<int>{2,
                                  new box<int>{2,
                                      new box<int>{3,
                                          new box<int>{5,
                                              new box<int>{9,nullptr}}}}}}}};
                                              

    box<int> *l2 = new box<int>{1,nullptr};
    box<int> *l3 = new box<int>{1,new box<int>{2,nullptr}};

    printList(l1);
    makeFib(l1);
    printList(l1);
    // doctest::Context().run();

    return 0;
}

