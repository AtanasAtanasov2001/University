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

int sum_tree(Node<int>* root) {
    if(!root)
        return 0;

    return root->data + sum_tree(root->left) + sum_tree(root->right);
}


int count_sub_tree(Node<int>* root, int k) {
    if(!root) {
        return 0;
    }

    if(sum_tree(root) == k){
        return 1 + count_sub_tree(root->left, k) + count_sub_tree(root->right, k);
    }

    count_sub_tree(root->left, k) + count_sub_tree(root->right, k);
}
