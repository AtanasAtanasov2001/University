#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>
bool has_cycle(std::list<int>* head) {

    std::vector<std::list<int>*> seen;
    std::list<int> *temp = head;
    while (head++ != nullptr)
    {
        if(std::find(seen.begin(), seen.end(), temp) != seen.end()) {
            return 1;
        } else {
            seen.push_back(temp);
            temp = temp++;//std::next(temp,1);

        }
    }
    return 0;
}

bool has_cycle(std::list<int>* head) {
    std::list<int>* current = head;
    if(head == nullptr) {
        return false;
    }
    else if (current++ == nullptr) {
        return false;
    }
    current = head;
    std::list<int>* previous = head;
    while(current != nullptr) {

        while (previous != current) {
            if(previous != current) {
            return true;
            }
            
            previous =previous++; //std::next(previous,1);
        }
        current = current++;//std::next(current,1);
        previous = head;
        
    }
    return true;
    
}