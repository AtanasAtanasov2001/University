#pragma once

#include <iostream>
#include <fstream>
#include <functional>
#include <unordered_map>
#include <utility>

class OPHashTable {
private:
   std::pair<std::string, int>** table;
   size_t capacity;
   size_t size;
   std::pair<std::string, int>* helper_pointer;// used in deletion -> for assigning an "empty" value to the deleted element

    
public:
    OPHashTable(){}
    OPHashTable(const int capacity): capacity(capacity){
        size = 0;
        table = new std::pair<std::string, int>*[capacity];
        for (size_t i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
        helper_pointer = new std::pair<std::string, int>("",-1);
    }
    OPHashTable(const OPHashTable& other) {
        this->table = other.table;
        this->capacity = other.capacity;
        this->size = other.size;
    }
    OPHashTable& operator=(const OPHashTable& other) {
        if(this != &other) {
            this->table = other.table;
            this->capacity = other.capacity;
            this->size = other.size;
        }
        return *this;
    }
    ~OPHashTable() {
        delete[] table;
        this->capacity = 0;
        this->size = 0;
        delete this->helper_pointer;
    }
    
    size_t hash(std::string key) const{
        std::hash<std::string> hasher;
        return hasher(key) % capacity;
    }

    bool insertWord(std::string element) {
        size_t hashIndex = hash(element);
        if(findWord(element)) {
            findWord(element)->second++;
        } else {
            std::pair<std::string, int>* temp = new std::pair<std::string, int>{element, 1};
            while((table[hashIndex] != nullptr)) {
                hashIndex++;
                hashIndex %= capacity;
            }
            size++;
            table[hashIndex] = temp; 
            return true;
        }
        return false;
    }
    bool deleteWord(std::string element) {
        size_t hashIndex = hash(element);

        while(table[hashIndex] != nullptr) {
            if(table[hashIndex]->first == element) {
                std::pair<std::string, int>* temp = table[hashIndex];

                table[hashIndex] = helper_pointer;
                size--;
                return true;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
        return false;
    }

    int operator[](std::string element) {
        size_t hashIndex = hash(element);

        while(table[hashIndex] != nullptr) {

            if(table[hashIndex]->first == element) {
                return table[hashIndex]->second;
            }
            hashIndex++;
            hashIndex %= capacity;
        }

        return -1;
    }

    bool find(std::string element) const{
        size_t hashIndex = hash(element);
        while(table[hashIndex] != nullptr) {
            if(table[hashIndex]->first == element) {
                return true;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
        return false;
    }
    std::pair<std::string, int>* findWord(std::string element) const{
        size_t hashIndex = hash(element);
        while(table[hashIndex] != nullptr) {
            if(table[hashIndex]->first == element) {
                return table[hashIndex];
            }
        hashIndex++;
        hashIndex %= capacity;
        }
        return nullptr;
    }
    
    size_t Size() const{
        return this->size;
    }

    bool Empty(){
        return this->size == 0;
    }
    void print() {
        for (size_t i = 0; i < capacity; i++)
        {
            if(table[i] != nullptr && table[i]->first != "") {
                std::cout << "The word: " << table[i]->first << " is present at the file: " << table[i]->second <<" times \n";
            } 
        }
    }


    std::pair<std::string, int>** getTable() const{
        return this->table;
    }

};