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

template<typename T>
bool are_equal(Node<T>* root, Node<T>* other ) {
    if(root == nullptr && other == nullptr){
        return true;
    }
    if(root == nullptr || other == nullptr) {
        return false;
    }

    return root->data == other->data && are_equal(root->left, other->left) && are_equal(root->right, other->right);
}

template <typename T>
bool is_sub_tree(Node<T>* root, Node<T>* other ) {
    if(other == nullptr) {
        return true;
    }
    if (root == nullptr && other != nullptr) {
        return false;
    }
    if(are_equal(root, other)){
        return true;
    }
    return is_sub_tree(root->left, other) || is_sub_tree(root->right, other);



}