#include "tree.hpp"
#include <string>
int main(){

    Node<int>* root = new Node<int>{1,
                        nullptr,
                        new Node<int>{2, 
                            nullptr, 
                            new Node<int>{3,
                                nullptr, 
                                new Node<int>{4,
                                    nullptr,
                                    new Node<int>{5, nullptr, nullptr}}}}};


    Node<int>* kur = new Node<int>{5, 
                        new Node<int>{3,
                            new Node<int>{2, nullptr, nullptr},
                            new Node<int>{4, nullptr, nullptr}},
                        new Node<int>{7, 
                            new Node<int>{6, nullptr, nullptr},
                            new Node<int>{8, nullptr,
                              new Node<int>{9, nullptr,
                                new Node<int>{10, nullptr, nullptr}
                              },
                            }
                            }};
                            
    Tree<int> kurec(root);
    // std::cout << kurec.height() << '\n';
    Tree<int> kurche(kur);
    // std::cout << kurche.height()  << '\n';
    std::cout << "KUREC \n";
    kurec.print();
    std::cout << "KURCHE \n";
    kurche.print();
    Tree<int> kurec2(kurec.balance_tree());
    std::cout << "KUREC2 \n";
    kurec2.print();
    Tree<int> kurche2(kurche.balance_tree());
    std::cout << "KURCHE2 \n";
    kurche2.print();
    
    // std::vector<int>* vec = kurec.tree_to_arr();
    // for(auto i: *vec){
    //     std::cout << i << " ";
    // }
    // std::cout << '\n';
    // std::vector<int>* vec2 = kurche.tree_to_arr();
    //  for(auto i: *vec2){
    //     std::cout << i << " ";
    // }


    return 0;
}