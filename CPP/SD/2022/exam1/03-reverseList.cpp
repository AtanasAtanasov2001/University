// #define DOCTEST_CONFIG_IMPLEMENT
// #include "doctest.h"
#include <iostream>
#include <stack>
template <typename T>
struct box {T data; box *next;};

/*Поставете тук реализация на функцията reverseList*/
template<typename T>
void reverseList(box<T>* first,int n){
    std::stack<T> s;
    box<T>* firstCopy = first;
    int helper = 0;
    while (firstCopy != nullptr && helper < n ) {
        s.push(firstCopy->data);
        firstCopy = firstCopy->next;
        helper++;
    }
    for (size_t i = 0; i < n; i++) {
        first->data = s.top();
        first = first->next;
        s.pop();
    }
}
// TEST_CASE("Reverse basic")
// {
//     box<int> *l1 = new box<int>{1,
//                          new box<int>{2,
//                              new box<int>{3,
//                                  new box<int>{4,
//                                       new box<int>{5,
//                                           new box<int>{6,
//                                               new box<int>{7,
//                                                   new box<int>{8,nullptr}}}}}}}};
//     reverseList(l1,4);
//     int expected[] = {4,3,2,1,5,6,7,8};
//     for (int x: expected)
//     {
//         CHECK(x==l1->data);
//         l1=l1->next;
//     }

// }

// TEST_CASE("Reverse edges")
// {
//     box<int> *l1 = new box<int>{1, new box<int>{2,nullptr}};
//     reverseList(l1,10);
//     CHECK(l1->data == 2);
//     CHECK(l1->next->data == 1);

//     CHECK_NOTHROW(reverseList(l1->next,10));
//     CHECK_NOTHROW(reverseList<int>(nullptr,10));
// }
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

int main()
{
        box<int> *l1 = new box<int>{1,
                          new box<int>{2,
                              new box<int>{3,
                                  new box<int>{4,
                                       new box<int>{5,
                                           new box<int>{6,
                                               new box<int>{7,
                                                   new box<int>{8,nullptr}}}}}}}};

     printList(l1);
     reverseList(l1,4);
     printList(l1);

    // doctest::Context().run();

    return 0;
}

