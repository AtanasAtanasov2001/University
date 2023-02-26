#include <iostream>
#include <cstring>
#pragma once
class CharArray{
    private:

    char* data;
    size_t length;

    public:
    CharArray() = default;
    CharArray(char* _data, size_t _length) : data(_data), length(_length){}
    ~CharArray(){
        data = nullptr;
        length = 0;
    }
    CharArray& operator+(const CharArray& other){
        size_t new_length = this->length + other.length ;
        char* new_arr = new char(new_length);
        for (size_t i = 0; i < this->length; i++)
        {
            new_arr[i] = this->data[i];
        }
        for (size_t i = 0; i < other.length; i++)
        {
            new_arr[this->length + i] = other.data[i];
        }
        delete[] this->data;
        this->length = new_length;
        this->data = new_arr;
        return *this;
    }
    bool validate(){
    
        for (size_t i = 0; i < this->length; i++)
        {
           if(this->data[i] != ' ' && this->data[i] != '.' && !(isdigit(this->data[i]) ) && !(isalpha(this->data[i]))) {
                return false;
           }
        }
        return true;
    }
    CharArray& operator=(const CharArray& other){
        if(this != &other){
            this->data = other.data;
            this->length = other.length;
        }
        return *this;
    }

    void print(){
        for (size_t i = 0; i < this->length; i++)
        {
            std::cout << this->data[i] << " ";
        }
        std::cout << '\n';
    }

};