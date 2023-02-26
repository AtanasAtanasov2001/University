// #define DOCTEST_CONFIG_IMPLEMENT
// #include "doctest.h"
#include <iostream>
template <typename T>
struct box {T data; box *next;};

/*Поставете тук реализация на функцията fillGaps*/
template <typename T>
void fillGaps(box<T>* head){

    if(head == nullptr || head->next == nullptr){
        // throw("Empty or with only 1 element");
        return ;
    }
    box<T>* current = head;
    box<T>* current_neighbour = current->next;
    box<T>* toAdd = nullptr;


    while(current->next != nullptr ){
            int K = current->data;
            int L = current_neighbour->data;
        if( K < L){
            for(int i = K + 1; i < L; i++){
                toAdd = new box<T>{i, current_neighbour};
                current->next = toAdd;
                current = toAdd;
            }

            
        } else {
            throw("Unordered list");
            // return nullptr;
        }
        current = current_neighbour;
        current_neighbour = current_neighbour->next;
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

// TEST_CASE("fillGaps basic")
// {
//     box<int> *l1 = new box<int>{1,
//                          new box<int>{3,
//                              new box<int>{5,nullptr}}};

//     fillGaps(l1);
//     for (int i = 1; i <= 5; ++i)
//     {
//         CHECK(l1->data == i);
//         l1 = l1->next;
//     }
// }

// TEST_CASE("fillGaps edges")
// {

//     box<int> *l2 = new box<int>{1,nullptr};
//     fillGaps(l2);
//     CHECK(l2->next == nullptr);

//     CHECK_NOTHROW(fillGaps<int>(nullptr));
// }

int main()
{
    box<int> *l1 = new box<int>{1,
                        new box<int>{3,
                        new box<int>{5,nullptr}}};
    box<int> *l2 = new box<int>{1,nullptr};
    box<int> *l3 = new box<int>{1,
                        new box<int>{3,
                        new box<int>{4,
                        new box<int>{8,nullptr}}}};
    printList(l1);
    fillGaps(l1);
    printList(l1);

    fillGaps(l2);
    fillGaps(l3);
    printList(l3);
    // doctest::Context().run();

    return 0;
}

