#pragma once

#include <vector>

template <typename T>
struct box
{
    T data;
    box *left;
    box *right;

    box(T _data, box<T>*_left, box<T> *_right) : data(_data), left(_left), right(_right) {};
};

/*
  Създава или променя елемента със следа trace
  в дървото с корен root. Приема, че родителя
  на елемента съществува.
*/
template <typename T>
bool setAt(box<T> *&root, const char *trace, const T& data)
{
    //trace: ""
    if(trace[0]==0)
    {
        if(root == nullptr)
        {
            root = new box<T>{data,nullptr,nullptr};
        } else 
        {
            root->data = data;    
        }
        return true;
    } else 
    {
        if(root==nullptr)
        {
            return false;
        }
        if(trace[0]=='L')
        {
            return setAt(root->left,trace+1,data);    
        } else if(trace[0]=='R')
        {
            return setAt(root->right,trace+1,data);    
        }
        return false;
    }
}

/*
  Проверка за еднаквост на две 
  двоични дървета
*/
template <typename T>
bool tree_equals(box<T> *t1, box<T> *t2)
{
    return t1==nullptr && 
           t2==nullptr ||
           t1 != nullptr && 
           t2 != nullptr && 
           t1->data == t2->data &&
           tree_equals(t1->left,t2->left) &&
           tree_equals(t1->right,t2->right);
}


/*
  Проверка дали елементите на масива v1
  са подмножество на елементите на масива v2
*/
template <typename T>
bool set_lteq(const std::vector<T> &v1,
              const std::vector<T> &v2)
{
    for (const T& el:v1)
    {
        if (std::find(v2.begin(),v2.end(),el)==v2.end())
        {
            return false;
        }
    }
    return true;
}

/*
  Проверка дали множеството на елементите на масива v1
  съвпада с множеството на елементите на масива v2
*/
template <typename T>
bool set_equals(const std::vector<T> &v1,
                const std::vector<T> &v2)
{
    return set_lteq(v1,v2) && set_lteq(v2,v1);
}