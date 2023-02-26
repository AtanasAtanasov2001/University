#include "LList.h"
#include <iostream>
#include <cassert>
#pragma once

template<typename T>
LList<T>::LList(){
    this->first = nullptr;
}

template<typename T>
LList<T>::LList(const LList<T> &other){
    if(this != &other){
        if (other.first == nullptr) {
            this->first = nullptr;
            return;
        }
        Node* curr = other.first->next;

        this->first = new Node(other.first->data, nullptr);
        Node* our = this->first;

        while (curr != nullptr) {
            our->next = new Node(curr->data, nullptr);
            curr = curr->next;
            our = our->next;
        }
    }
}

template<typename T>
LList<T>::~LList(){
    if(this->first == nullptr){
        delete this->first;
        return;
    }
    Node* curr = this->first;
    Node* cNext;

    while (curr != nullptr) {
        cNext = curr->next;
        delete[] curr;
        curr = cNext;
    }
}
template<typename T>
LList<T>& LList<T>::operator=(const LList<T> &other){
    if(this != &other){
        if (other.first == nullptr) {
            this->first = nullptr;
            return *this;
        }
        Node* curr = other.first->next;

        this->first = new Node(other.first->data, nullptr);
        Node* our = this->first;

        while (curr != nullptr) {
            our->next = new Node(curr->data, nullptr);
            curr = curr->next;
            our = our->next;
        }
    }
    return *this;
}

template<typename T>
bool LList<T>::push(T new_value){
    if(this->first == nullptr){
        this->first = new Node(new_value, nullptr);
        return true;
    }
    Node* curr = this->first;
    while (curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = new Node(new_value, nullptr);
    return true;
}
template<typename T>
bool LList<T>::pop(){
    if(this->first == nullptr){
        return false;
    }
    Node* curr = this->first;
    Node* toDelete = curr->next;
    while (toDelete->next != nullptr) {
        curr = curr->next;
        toDelete = toDelete->next;
    }
    curr->next = nullptr;
    delete[] toDelete;
    return true;
}

template<typename T>
const typename LList<T>::Node& LList<T>::top() const{
    assert("Empty list");

    Node* curr = this->first;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    return *curr;
}

template<typename T>
void LList<T>::print()const {
    if(this->first == nullptr){
        std::cout << "The list is empty \n";
    }
    Node* curr = this->first;
    while (curr != nullptr){
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

template<typename T>
unsigned int LList<T>::size() const{
    if(this->first == nullptr){
        return 0;
    }
    Node* curr = this->first;
    unsigned int counter = 0;
    while (curr != nullptr){
        curr = curr->next;
        counter++;
    }
    return counter;
}