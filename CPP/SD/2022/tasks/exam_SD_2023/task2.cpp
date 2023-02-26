#include <iostream>
#include <queue>
#include <vector>
template <typename T>

struct TNode { 
    T data; 
    std::vector<TNode*> children; 
};

template <typename T>
bool ordered_levels (TNode<T>* tree){
    bool flag = false;
    std::queue<TNode<T>*> BFS_helepr;
    BFS_helepr.push(tree);
    BFS_helepr.push(nullptr);
    while (tree)
    {
        TNode<T>* current = BFS_helepr.front();
        std::vector<TNode<T>*> values;
        BFS_helepr.pop();
        if(current == nullptr){
            if(BFS_helepr.empty()) break;
            else {
                BFS_helepr.push(nullptr);
            }
            continue;
        } 
        for (size_t i = 0; i < current->children.size(); i++)
        {
            BFS_helepr.push(current->children[i]);
            values.push_back(current->children[i]);
        }
        for (size_t i = 0; i < values.size() - 1; i++)
        {
            if(values[i]->data <= values[i + 1]->data){
                flag = true;
            }
            else{
                flag = false;
            }
        }   
    }
    return flag;
}

int main(){
    TNode<int> *t1 = new TNode<int> {0,{
                                     new TNode<int> {1,{
                                                     new TNode<int>{-1,{}},
                                                     new TNode<int>{1,{}}
                                     }},
                                     new TNode<int> {2,{
                                                     new TNode<int>{5,{
                                                                    new TNode<int>{7,{}},
                                                                    new TNode<int>{8,{}}
                                                     }}
                                     }},
                                     new TNode<int> {3,{}}
                     }};

    TNode<int> *t2 = new TNode<int> {0,{
                                     new TNode<int> {1,{
                                                     new TNode<int>{-1,{}},
                                                     new TNode<int>{1,{}}
                                     }},
                                     new TNode<int> {4,{
                                                     new TNode<int>{5,{
                                                                    new TNode<int>{7,{}},
                                                                    new TNode<int>{8,{}}
                                                     }}
                                     }},
                                     new TNode<int> {3,{}}
                     }};
    std::cout << ordered_levels(t1);
    return 0;
}