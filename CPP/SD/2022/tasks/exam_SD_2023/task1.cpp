#include <iostream>
#include <vector>
#include <utility>

template <typename T>
struct box{
    T data;
    box* next;
    box(T _data, box<T>* _next):data(_data), next(_next){}
};

template<typename T>
int occurencies(box<T>* list, T value){
    int counter = 0;
    while(list != nullptr){
        if(list->data == value){
            counter++;
        }
        list = list->next;
    }
    return counter;
}

template <typename T>
T most_common(box<T>* list){
    if(!list){
        throw std::bad_alloc("empty list");
    }
    box<T>* current = list;
    int counter = 0;
    T to_return;
    while(current->next != nullptr){
        // std::cout << current->data << " ";
        if(occurencies(list, current->data) < occurencies(list, current->next->data)){
            to_return = current->next->data;
        }
        current = current->next;
    }
    return to_return;

}
// 1 2 3 4 4 2 3 3
int main(){
    box<int>* list = new box<int>(1, new box<int>(2, 
                        new box<int>(3, new box<int>(4, new box<int>(4, 
                        new box<int>(2, new box<int>(3, new box<int>(3, nullptr))))))));

    box<int>* list1 = new box<int>(1, new box<int>(2, 
                        new box<int>(4, new box<int>(4, new box<int>(4, 
                        new box<int>(3, new box<int>(3, new box<int>(3, nullptr))))))));
    // std::cout << occurencies(list,3);
    std::cout << most_common(list);
    return 0;
}