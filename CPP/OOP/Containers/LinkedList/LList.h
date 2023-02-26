#pragma once
#include "Box.cpp"
#include <fstream>
#include <cassert>

template<typename T>
class LList
{
    private:
    Box<T>* first;

    public:
    LList();
    LList(const LList<T>&);
    LList& operator=(const LList<T>&);
    ~LList();

    void print();
    void push(const T&);
    void push_back(const T&);
    void push_back_box(Box<T>&);
    void pop();
    void pop_back(); 
    void clear();
    void insertAfter(const T&, int); 
    void deleteAt(int);
    int size() const;
    const Box<T>* front() const;
    bool empty() const;
    LList& removeDublicates();
    void read(const char* file_name);

    friend std::ostream& operator<< (std::ostream &out, const LList<T>& list)
    {
        Box<T>* current = list.first;
        while(current != nullptr)
        {
            out << current->data << " ";
            current = current->next;
        }
        out << "nullptr" << std::endl;
        return out;  
    }
    
    friend std::istream& operator>>(std::istream& in , LList<int>& list)
    { 
        std::cout << "sth";
        if (!in.good()) 
        {
            throw std::invalid_argument("Could not open file!");
        }
        while(!in.eof()) 
        {
            std::cout <<"here";
            Box<T>* current = new Box<T>();
            in >> current->data;
            list.push_back_box(*current);
            current = current->next;
        }
        std::cout << "nullptr";
        return in;
    }
};