#pragma once
#include "String.h"
#include <exception>
//copy for strings
void String::copy(const String& other)
{
    length = other.length;
    data = new char[length + 1];

    for (size_t i = 0; i < length; i++)
    {
        data[i] = other.data[i];
    }
    data[length] = '\0';
}
//copy for char array

void String::destroy()
{
    delete[] data;
}

//default constructor
String::String()
{
    length = 0;
    data = new char[length + 1];  
    data[length] = '\0';  
}

// constructor with char array
String::String(const char* other)
{
    length = strlen(other);
    data = new char[length + 1];
    strcpy(data,other);
    data[length] = '\0'; 
    
}


//copy constructor
String::String(const String& other)
{
    this->copy(other);
}
//operator = with char array
String& String::operator=(const char* other)
{

    this->destroy();
    this->copy(*(new(std::nothrow) String{other})); 

    return *this;
}

//operator = with string
String& String::operator=(const String& other)
{
    if(this != &other)
    {
        this->destroy();
        this->copy(other); 
    }
    return *this;
}
//destructor
String::~String()
{
    this->destroy();
}

//Access funcs
bool String::isEmpty() const
{
    return length == 0;
}

size_t String::Length() const
{
    return length;
}

char* String::getData() const
{
    return this->data;
}
char String::operator[](int i) const
{ 
    
    if(i < this->Length())
    {
        return data[i];
    }
    else if(i < 0)
    {
        throw std::out_of_range("Index is a negative number");
    }
    throw std::out_of_range("Index too big to access in vector");
}
bool String::operator==(String& other) const
{
    bool flag = false;
    if (strcmp(this->data, other.data) == 0)
    {
        flag = true;
    }
    
    return flag;
}
bool String::operator==(const char* other) const
{
    bool flag = false;
    if (strcmp(this->data, other) == 0)
    {
        flag = true;
    }
    
    return flag;
}
bool String::operator!=(String& other) const
{
    bool flag = false;
    if (!(strcmp(this->data, other.data) == 0))
    {
        flag = true;
    }
    return flag;
}
bool String::operator!=(const char* other) const
{
    bool flag = false;
    String other2 = other;
    if (!((strcmp(this->data, other2.data) == 0)))
    {
        flag = true;
    }
    return flag;
}
String& String::push_back(const char& other)
{
    data[length++] = other;
    data[length] = '\0';
    
}


String& String::pop_back()
{
    char* data_ = new char[length];

    if(this->Length() <= 0)
    {
        throw std::range_error("The string is empty");
    }
    for (size_t i = 0; i < length; i++)
    {
        data_[i] = this->data[i]; 
    }

    data_[length - 1] = '\0';
    this->destroy();
    this->copy(*(new(std::nothrow) String{data_}));
    return *this;
}

std::ostream& operator<< (std::ostream& out, const String& other)
{
    out << other.data;
    return out;
}
std::istream& operator>>(std::istream& in, String& str) {

  char buffer[1024];
  in >> buffer;

  str.destroy();
  str.data = new char[strlen(buffer) + 1];

  strcpy(str.data, buffer);

  return in;
}