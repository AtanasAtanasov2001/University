#include <iostream>
#include <vector>
#include <algorithm>
template<typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T _data, Node<T>* _left, Node<T>* _right) : data(_data), left(_left), right(_right){}

    Node() = default;
};

// 1. Algorithm to convert Binary Search Tree into Balanced Binary Search Tree
// 2. Find nodes which are at a distance k from root in a Binary Tree
// 3. Find if a given Binary Tree is a Sub-Tree of another Binary Tree
// 4. Counting subtrees where nodes sum to a specific value
// 5. Invert / Reverse a Binary Tree
// 6. Convert binary tree to binary search tree



template<typename T>
class Tree{

    private:
    Node<T>* root;


    bool are_equal(Node<T>* root, Node<T>* other ) {
    if(root == nullptr && other == nullptr){
        return true;
    }
    if(root == nullptr || other == nullptr) {
        return false;
    }

    return root->data == other->data && are_equal(root->left, other->left) && are_equal(root->right, other->right);
}
    Node<T>* balance_tree(std::vector<T>* _vec, int start, int end ){
        if(start > end){
            return nullptr;
        }
        int rootEl = (start + end) / 2;
        Node<T>* root = new Node<T>{(*_vec)[rootEl], nullptr, nullptr};
        root->left = balance_tree(_vec,start, rootEl-1);
        root->right = balance_tree(_vec,rootEl+1, end);
        return root;
    }

    //1,2,3,4,5
    //
    std::vector<T>* tree_to_array(Node<T>* _root,std::vector<T>* _vec){
        if(_root == nullptr) {
            return _vec;
        }

        _vec->push_back(_root->data);
        tree_to_array(_root->left, _vec);
        tree_to_array(_root->right, _vec);
    }
    size_t height(Node<T>* _root){
        if(_root == nullptr) {
            return 0;
        }
        return 1 + (std::max(height(_root->left), height(_root->right)));
    }

    void print(const std::string& prefix, const Node<T>* node, bool isLeft) {
    if( node != nullptr )
    {
      std::cout << prefix;

      std::cout << "|--";

      std::cout << node->data << std::endl;

      print( prefix + (isLeft ? "|   " : "    "), node->left, true);
      print( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
  }

  public:
    Tree(Node<T>* _root): root(_root){};
    void print() {
        print("", root, false);
    }
    size_t height(){
        return height(root);
    }
    std::vector<T>* tree_to_arr(){
        std::vector<T>* helper = new std::vector<T>();
        return tree_to_array(root, helper);
    }

    Node<T>* balance_tree(){
        std::vector<T>* sorted_array = tree_to_arr();
        std::sort(sorted_array->begin(), sorted_array->end());
        return balance_tree(sorted_array, 0, sorted_array->size() - 1);
    }
    bool is_sub_tree( Node<T>* other ) {
        if(other == nullptr) {
            return true;
        }
        if (this->root == nullptr && other != nullptr) {
            return false;
        }
        if(are_equal(this->root, other)){
            return true;
        }
        return is_sub_tree(this->root->left, other) || is_sub_tree(this->root->right, other);
    }
    void reverse() {
        if(!this->root){
            return;
        }
        Node<T>* temp = this->root->left;
        this->root->left = this->root->right;
        this->root->right = temp;
        reverse(this->root->left);
        reverse(this->root->right);
    }
    void add(const T& value) {
    if (this->root->value > value) {
      if(!this->root->left) {
        this->root->left = new node(value);
      } else {
        add(value,this->root->left);
      }      
    } else if(this->root->value < value) {
      if(!this->root->right) {
        this->root->right = new node(value); 
      } else {
        add(value, this->root->right);
      }
    }
}


};
    
