#include <iostream>
#include <list>
#include <iterator>


int FindMergePointOflists(std::list<int> * head1,std::list<int> * head2 ) {
    std::list<int> *list1 = head1;
    std::list<int> *list2 = head2;

    while(list1 != nullptr) {
        while(list2 != nullptr) {
            if(list1 == list2) {
                return list1->front();
            }
            list2 = std::next(list2,1);
        }
        list2 = head2;
        list1 = std::next(list1,1);
    }
    return -1;
}

// int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
//     while(head1){
//         SinglyLinkedListNode *tmp = head1->next;
//         head1->next = NULL;
//         head1 = tmp;
//     }
    
//     while(head2){
//         if(head2->next == NULL){
//             return head2->data;
//         }
//         head2 = head2->next;
//     }
//     return 0;

// }