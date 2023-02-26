#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <cmath>

template <typename T>
struct Node{
    T data;
    std::vector<Node*> tree;
    Node() = default;
    Node(T _data, std::vector<Node*> _tree): data(_data), tree(_tree){}
};

struct node{
    int data;
    node* left;
    node* right;
    node(int _data, node* _left, node*_right) : data(_data), left(_left), right(_right){}
};


struct box{
    double data;
    box* next;
    box() = default;
    box(double _data, box* _next ): data(_data), next(_next){}
};

template<typename T>
void read(Node<T>* tree, int level){
    // std::string to_return;
    std::queue<Node<T>*> BFS_helepr;

    BFS_helepr.push(tree);
    BFS_helepr.push(nullptr);
    while (level != 0)
    {
        Node<T>* current = BFS_helepr.front();
        BFS_helepr.pop();
        if(current == nullptr){
            level--;
            if(BFS_helepr.empty()) break;
            else {
                BFS_helepr.push(nullptr);
            }
            continue;
        } 
        for (size_t i = 0; i < current->tree.size(); i++)
        {
            BFS_helepr.push(current->tree[i]);
        }    
        
    }

    while(BFS_helepr.size() != 0){
        std::cout << BFS_helepr.front()->data;
        BFS_helepr.pop();
    }
}


bool isBSTree(node* tree ){
    bool isBS = true;

    if(!tree) return isBS;

    if((tree->left == nullptr && !(tree->right->data > tree->data)) || (!(tree->left->data < tree->data) && tree->right == nullptr)){
        std::cout << "randi da go duha \n";
        isBS = false;
    }

    if (isBS == false){
        return false;
    }
    
    if(!(tree->left->data < tree->data) || !(tree->right->data > tree->data)){
        std::cout << "angelkov za kusmet \n";
        isBS = false;
    }
    return isBS && isBSTree(tree->left) && isBSTree(tree->right);
}

int height_of_tree(node* tree){
    if(!tree) return 0;

    return   1 + std::max( height_of_tree(tree->left), height_of_tree(tree->right));
}

int num_of_nodes(node* tree){
    if(!tree) return 0;

    return 1 + num_of_nodes(tree->left) + num_of_nodes(tree->right);
}

void balance_of_tree(node* tree){
    if((height_of_tree(tree->left) > 1 + height_of_tree(tree->right) || height_of_tree(tree->right) > 1 + height_of_tree(tree->left))){
        std::cout << "Neither balanced, not perfectly balanced! \n";
        return;
    }
    if((height_of_tree(tree->left) <= 1 + height_of_tree(tree->right) || height_of_tree(tree->right) <= 1 + height_of_tree(tree->left))
        && (num_of_nodes(tree) == std::pow(2,height_of_tree(tree)) - 1 )) {
            std::cout << "Balanced and perfectly balanced tree; \n";
            return;
        }
    if((height_of_tree(tree->left) <= 1 + height_of_tree(tree->right) || height_of_tree(tree->right) <= 1 + height_of_tree(tree->left)))
    {
        std::cout << "Balanced tree \n";
        return;
    }

}

// void reorder(node* tree){
//     if(!tree) return;

//     if(tree->data > tree->right->data || tree->left->data > tree->data){
//         node* 
//     }
// }

void fixList(box*& list){
    if(list == nullptr){
        return;
    }
    box* copy = list;
    if(copy->next && (copy->data == copy->next->data/2)){
        box* toRemove = copy;
        copy = copy->next;
        list = list->next;
        delete toRemove;
    }
    while(copy && copy->next){
        box* current = copy;
        box* next = current->next;
        box* neext = next->next;

        if(neext == nullptr){
            if(next->data == current->data/2){
                box* toRemove = next;
                current->next = neext;
                delete toRemove;
            }
        }
        else if(next->data == (current->data + neext->data)/2){
            box* toRemove = next;
            current->next = neext;
            delete toRemove;
        }
        copy = copy->next;
    }

}
void printList(box* list){
    while(list){
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << "\n";
}

int analyzeTree(node* root, double number){
    int counter = 0;
    std::queue<node*> elements;
    elements.push(root);
    while (!elements.empty())
    {   
        std::vector<node*> numbers;
        // std::cout << elements.size() << " \n";
        int size = elements.size();
        for (size_t i = 0; i < size; i++)
        {   
            // std::cout << elements.front()->data << "\n"; 
            node* helper = elements.front();
            numbers.push_back(helper);
            elements.pop();
            if(helper->left){
                elements.push(helper->left);
            }
            if(helper->right){
                elements.push(helper->right);
            }
        }
        double sum_vector = 0;
        for (size_t i = 0; i < numbers.size(); i++)
        {
            // std::cout << numbers[i]->data << "\n";
            sum_vector += numbers[i]->data;
        }
        if(sum_vector/(double)numbers.size() == number){
            return counter;
        }
        counter++;
    }
    return -1;
}
int main(){

    // std::vector<Node<char>*> b_children;
    // b_children.push_back (new Node<char>('d', std::vector<Node<char>*>()));
    // b_children.push_back (new Node<char>('f', std::vector<Node<char>*>()));

    // std::vector<Node<char>*> a_children;
    // b_children.push_back (new Node<char>('c', std::vector<Node<char>*>()));
    // b_children.push_back (new Node<char>('m', std::vector<Node<char>*>()));
    // b_children.push_back (new Node<char>('n', std::vector<Node<char>*>()));

    // std::vector<Node<char>*> trie;
    // trie.push_back(new Node<char>('b', b_children));
    // trie.push_back(new Node<char>('c', std::vector<Node<char>*>()));
    // trie.push_back(new Node<char>('a', a_children));

    // Node<char> *root = new Node<char>('a',trie);

    node *tree = new node(5, 
                        new node(3, 
                                new node(3,nullptr,nullptr),nullptr), 
                        new node(7,
                                new node(6,nullptr,nullptr),
                                new node(9,nullptr,
                                        new node(10,nullptr,nullptr))));
    // // read(root, 2);
    // balance_of_tree(tree);
    // std::cout << height_of_tree(tree);
    // std::cout << num_of_nodes(tree);
    // std::cout << isBSTree(tree);

    // box *list = new box(3.5, new box(7,new box(6, new box(5, new box(9, new box(9,nullptr))))));
    // box* first = nullptr;
    // box* second = new box(0,nullptr);
    // box* third = new box(2.5, new box(5,nullptr));
    // printList(list);
    // fixList(list);
    // printList(list);
    
    // printList(first);
    // fixList(first);
    // printList(first);
        
    // printList(second);
    // fixList(second);
    // printList(second);    
    
    // printList(third);
    // fixList(third);
    // printList(third);
    std::cout << analyzeTree(tree,6);
    return 0;
}