#include <iostream>
#include <string>
#include <vector>


template<typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;

    Node(T value, Node* _left = nullptr, Node* _right = nullptr) : data(value), left(_left), right(_right) {}

};

template <typename T>
void reverse(Node<T>* root) {
    if(!root){
        return;
    }
    Node<T>* temp = root->left;
    root->left = root->right;
    root->right = temp;
    reverse(root->left);
    reverse(root->right);
}