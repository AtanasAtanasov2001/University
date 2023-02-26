#include <iostream>
#include <cmath>
#include <stack>
#include <exception>
#include <cstring>


template<typename T>
struct Node {
    T data;
    Node* next;
};
//TASK1========================================================>
// Напишете функция, която трябва да сортира списък по абсолютната стойност на неговите елементи. 
// Пример: Вход: -3 -> 1 -> 2 -> -10 -> 11 -> -7 Изход: 1 -> 2 -> -3 -> -7 -> -10 -> 11

// Напишете друга фуннкция, която сортира списък, вече сортиран по абсолютната стойност на неговите елементи.
//  Пример: Вход: 1 -> 2 -> -3 -> -7 -> -10 -> 11 Изход: -10 -> -7 -> -3 -> 1 -> 2 -> 11

template<typename T>
void sort_by_absolute_value(Node<T>* first) {
    if(first == nullptr){
        return;
    }
    Node<T>* curr = first;
    Node<T>* next = curr->next;
    bool flag = false;

    while (!flag) {
        flag = true;
        curr = first;
        next = curr->next;
        while (next != nullptr) {
            if(abs(curr->data) > abs(next->data)) {
                T helper = next->data;
                next->data = curr->data;
                curr->data = helper;
                flag = false;
            }
            next = next->next;
            curr = curr->next;
        }
    }
}
template <typename T>
Node<T>* sort_sorted_by_abs(Node<T>* first) {
    sort_by_absolute_value(first);
    Node<T>* curr = first;
    Node<T>* next = curr->next;
    Node<T>* helper = curr;
    while (next != nullptr){
        if(next->data < 0) {
            curr->next = next->next;
            next->next = helper;
            helper = next;
            next = curr->next;
        } else {
            curr = curr->next;
            next = next->next;
        }

    }
    return helper;
}
//TASK2========================================================>
// Проверете дали даден едносвързан списък е палиндром, използвайки stack.
//  Проверете дали даден едносвързан списъм е палиндром без да използвате stack. Пример: Вход: 2 -> 3 -> 3 -> 2 Изход: YES
template <class T>
bool is_palindrome_stack(Node<T>* head){
    Node<T>* current = head;
    std::stack<T> s;
    while (current != nullptr){
        s.push(current->data);
        current = current->next;
    }
    current = head;
    while (current != nullptr) {
        if(s.top() == current->data){
            s.pop();
            current = current->next;
        } else {
            return false;
        }
    }
    return true;
}

// template<class T>
// Node<T>* recursion_reverse(Node<T>* current, Node<T>* reversed){
//     if(current == nullptr){
//         return reversed;
//     }
//     Node<T>* next = new Node<T>{current->data, reversed};
//     recursion_reverse(current->next, next);

// }

// template<class T>
// void recursion_reverse_two(Node<T>* current, Node<T>* first, bool flag, int count){
//     if(current == nullptr){
//         return;
//     }

//     if (flag) {
//         recursion_reverse_two(current->next, first, true, ++count);
//         for (size_t i = 0; i < count; i++) {
//             first = first->next;
//         }
//         recursion_reverse_two(first, current, false, 0);
//     } else {
//         std::cout << "test: " << current->data << ":" << first->data << std::endl;
//     }
//         // std::cout << "test: " << current->data << ":" << first->data << std::endl;
//     // std::cout << current->data << " ";
// }
//N<-1<- 2<- 3
// reversed -> 3->2->1
// curr     -> 1->2->3


// template<class T>
// bool is_palindrome_no_stack(Node<T>* head){
//     Node<T>* reverse_head = recursion_reverse<T>(head,nullptr);
//     while (head != nullptr) {
//         if(head->data != reverse_head->data){
//             return false;
//         }
//         head = head->next;
//         reverse_head = reverse_head->next;
//     }
//     return true;
// }

// template<class T>
// bool is_palindrome_no_stack_two(Node<T>* head){
//     return recursion_reverse_two(head, head);
// }


//TASK3========================================================>
//Проверете дали даден списък съдържа цикъл.
//1->2->3->4->2
//|  |  |
//ab a  b      


template <class T>
bool has_cycle(Node<T>* head) {
    Node<T>* turtle = head;
    Node<T>* rabbit = head->next;
    while (turtle->next != nullptr && rabbit->next->next !=nullptr) {
        if(turtle == rabbit){
            return true;
        }
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    return false;
}


//TASK4===========================================================
//Намерете елемент n в едносвързан списък, използвайки двоично търсене.
//greater -> right
//smaller -> left
int size(Node* head) {
  int count = 0;

  while (head != nullptr) {
    count++;
    head = head->next;
  }

  return count;
}

Node* binary_search(Node* head, int n) {
  int index = size(head)/2;
  Node* curr = head;
  for (size_t i = 0; i < index; i++)
  {
    curr = curr->next;
  }

  while (curr != nullptr) {
    std::cout << index << std::endl;

    if (curr->data == n) {
      break;
    } else if (curr->data > n) {
      index = index/2;
    } else if (curr->data < n) {
      index += (size(head)-index)/2+1;
    }


    if (index >= size(head) || index < 0) {
      curr = nullptr;
      break;
    }

    curr = head;
    for (size_t i = 0; i < index; i++)
    {
      curr = curr->next;
    }
  }

  return curr;
}


// TASK 5 (template)
// Групирайте всички елементи, които са на нечетна позиция, последвани от тези на четна позиция, на подаден едносвързан списък.
//  Пример: Вход: 1 -> 2 -> 3 -> 4 -> 5 Изход: 1 -> 3 -> 5 -> 2 -> 4

Node* group(Node* head) {
  std::cout << "kur" << std::endl;

  Node* res = new Node{head->data, nullptr};
  Node* resCurr = res;

  Node* curr = head;

  for (size_t i = 0; curr; i++)
  {
    if (i%2 == 0 && i != 0)
    {
      resCurr->next = new Node{curr->data, nullptr};
      resCurr = resCurr->next;
    }
    curr = curr->next;
  }

  curr = head;
  for (size_t i = 0; curr; i++)
  {
    if (i%2 != 0)
    {
      resCurr->next = new Node{curr->data, nullptr};
      resCurr = resCurr->next;
    }
    curr = curr->next;
  }

  return res;
}


template <typename T>
void print(Node<T>* head) {
    while (head != nullptr){
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main() {

    Node<int>* kur = new Node<int>{-3, 
                        new Node<int>{1, 
                        new Node<int>{2, 
                        new Node<int>{-10, 
                        new Node<int>{11,
                        new Node<int>{-7,nullptr}}}}}};
    // print(kur);
    // //sort_by_absolute_value(kur);
    // Node<int>* chep = sort_sorted_by_abs(kur);
    // print(chep);

    Node<int>* sperma = new Node<int>{1,
                            new Node<int>{2,
                            new Node<int>{3,nullptr}}};

    Node<int>* a = new Node<int>{2,nullptr};
    Node<int>* b = new Node<int>{2,nullptr};
    Node<int>* c = new Node<int>{2,nullptr};

    a->next = b;
    b->next = c;
    c->next = nullptr;


    // Node<int>* menzis = new Node<int>{2,
    //                         new Node<int>{3,
    //                         new Node<int>{4, 
    //                         new Node<int>{2,sperma}}}};
    // std::cout << std::boolalpha << is_palindrome_stack(sperma);
    // std::cout << std::boolalpha << is_palindrome_stack(kur);
    // std::cout << is_palindrome_no_stack_two(kur) << "\n";
    // std::cout << is_palindrome_no_stack_two(sperma);
    // recursion_reverse_two<int>(sperma,sperma,true, 0);

    std::cout << has_cycle(a);
    
    return 0;
}

//-3 1 2 -10 11 -7
//-7 11 -10 2 1 -3
//curr -> -3 -> -7
//first-> -7