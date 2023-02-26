#pragma once

#include <iostream>
#include <exception>
#include <cassert>

class BSTree {
  private:
    struct node {
      int value;
      node* left;
      node* right;

      node(int value, node* left = nullptr, node* right = nullptr) : value(value), left(left), right(right) {}
    } *root;

    void clear_helper(node* begin) {
      if(begin->left) {
        clear_helper(begin->left);
        delete[] begin->left;
        begin->left = nullptr;

      }
      if(begin->right) {
        clear_helper(begin->right);
        delete[] begin->right;
        begin->right = nullptr;
      }
      delete[] begin;
    }

    void clear() {
      this->clear_helper(this->root);
      root = nullptr;
    }
    
    void copy_helper(node* start) {
      if (start->left != nullptr) {
          add(start->left->value);
          copy_helper(start->left);
      } if (start->right != nullptr){
          add(start->right->value);
          copy_helper(start->right);
      }
    }

    void copy(node* start) {
      assert(this->isEmpty());

      if (start) {
        this->add(start->value);
      }

      copy_helper(start);
    }

    void add_helper(const int &value, node* curr) {
      if (curr->value > value) {
        if(!curr->left) {
          curr->left = new node(value);
        } else {
          add_helper(value,curr->left);
        }      
      } else if(curr->value < value) {
        if(!curr->right) {
          curr->right = new node(value); 
        } else {
          add_helper(value, curr->right);
        }
      }
    }
    
    void print_helper(node* curr) {
      if(!curr){
        std::cout << "{ }"; 
      }else {
        std::cout << "{ value: " << curr->value << ", left: "; 
        print_helper(curr->left);
        std::cout << ", right: ";
        print_helper(curr->right);
        std::cout << " }"; 

      }
    }
    /*
          |-|
        |-| |-|
     |-||-| |-||-|
*/
  public:
  
    BSTree() : root(nullptr){}
    BSTree(const BSTree &other) : root(nullptr) { this->copy(other.getRoot()); }
    BSTree& operator= (const BSTree &other) {
      if(this != &other) {
        this->clear();
        this->copy(other.getRoot());
      }
      return *this;   
    }
    ~BSTree() { this->clear(); }

    node* getRoot() const {
      return this->root;
    }
    
    bool isEmpty() {
      return root == nullptr;
    }

    void add(const int& value) {
      if(isEmpty()) {
        root = new node(value);
      } else {
        add_helper(value,this->getRoot());
      }
    }

    void search(const int& value) const {
        if(root == nullptr){
          std::cout << "There are no elements in the tree! Function add() to add elements!?" << std::endl;
        } 
        node *current = root;
        while (current)
        {
          if(current->value == value) {
            std::cout << "Element: " << value << " found!" << std::endl;
            return;
          }

          if(current->value > value) {
            current = current->left;
          } else if(current->value < value) {
              current = current->right;
          }
        }
        std::cout << "Element: " << value << " not found!" << std::endl;
    }


    void print() {
      print_helper(this->getRoot());
      std::cout << std::endl;
    }

    
};

