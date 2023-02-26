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
void print_nodes_at_level(Node<T>* root, int k){
    if(root == nullptr){
        return;
    }
    if(k == 0) {
        std::cout << root->data << " ";
        return;
    }
    print_nodes_at_level(root->left, k-1);
    print_nodes_at_level(root->right, k-1);

}