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

//===================UNBALANCED=============================

template <typename T>
void add(const T& value, Node<T>* root) {
    if (root->value > value) {
      if(!root->left) {
        root->left = new node(value);
      } else {
        add(value,root->left);
      }      
    } else if(root->value < value) {
      if(!root->right) {
        root->right = new node(value); 
      } else {
        add(value, root->right);
      }
    }
}

template <typename T>
 std::vector<T> tree_to_vec(Node<T>* root){
    std::vector<T> vector;
    if(!root) {
        return vector;
    }
    vector.push_back(root->data);
    tree_to_vec(root->left, vector);
    tree_to_vec(root->right, vector);
}

template<typename T> 
void delete_BST(Node<T>* root) {
    if(!root){
        return;
    }
    if(root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr;
        return;
    }
    delete_BST(root->left);
    delete_BST(root->right);
}

template<typename T>
Node<T>* convert_to_BST(Node<T>* root) {
    Node<T>* to_return = new Node();

    std::vector<T> vec = tree_to_vec(root);
    for (size_t i = 0; i < vec.size(); i++)
    {
        add(vec[i], to_return);
    }
    return to_return;
}

//===================BALANCED======================