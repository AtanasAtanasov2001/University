#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
class String
{
    private:
    
    size_t length;

    void copy(const String&);
    void destroy();
    char* data;
    public:
    
    //the big 4
    String();
    String(const char*);
    String(const String&);

    String& operator= (const char*);
    String& operator= (const String&);
    ~String();
 
    //access
    bool isEmpty() const;
    size_t Length() const;
    char* getData() const;
   
    //char operator[](size_t) const;
    char operator[](int) const;//one exception is the index is too big, and one if the index is negative
    bool operator==(String& other) const;
    bool operator==(const char* other) const;
    bool operator!=(String& other) const;
    bool operator!=(const char* other) const;
    String& push_back(const char&);
    String& pop_back();// one exception if the string is empty
    friend std::ostream& operator<< (std::ostream& out, const String&);
    friend std::istream& operator>> (std::istream& in, String& other);

};