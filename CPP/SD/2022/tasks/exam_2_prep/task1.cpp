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
void save_tree(Node<T>* root, std::vector<Node<T>*>& vector){
    if(!root) {
        return;
    }

    save_tree(root->left, vector);
    vector.push_back(root);
    save_tree(root->right, vec);

}

template <typename T>
Node<T>* balance_tree_helper(std::vector<Node<T>*>& vec, int start, int end ) {

    if(start >end){
        return nullptr;
    }
    int mid_el = (end + start)/2;
    Node<T>* root = v[mid_el]
    root->left = balance_tree_helper(vec, start, mid_el - 1);
    root->right = balance_tree_helper(vec, mid_el + 1,end );
    return root;
}

template<typename T>
void balance_tree(Node<T>*& root){
    std::vector<Node<T*> vec;
    save_tree(root, vec);
    root = balance_tree_helper(vec, 0, vec.size() - 1);
}
