// #define DOCTEST_CONFIG_IMPLEMENT
// #include "../doctest.h"
#include <iostream>
#include <algorithm>
#include "../treeutils.cpp"
#include <vector>

/*
======================
Решение на задачата:
======================
*/
template <typename T>
size_t count_elements_level(box<T>* t, size_t level){
    if(t == nullptr){
        return 0;
    }
    if(level == 0){
        return 0;
    }
    return 1 + count_elements_level(t->left, level - 1) + count_elements_level(t->right, level - 1);
}
template <typename T>
size_t height(box<T>* t){
    if(t == nullptr){
        return 0;
    }
    return 1 + std::max(height(t->left), height(t->right));
}

template <typename T>
std::vector<T> levelsGrowing(box<T>* t){
    std::vector<int> to_return {};
    if(t == nullptr){
        return to_return;
    }
    size_t begin = 2;

    if(count_elements_level(t, begin) > count_elements_level(t, begin-1)){
        to_return.push_back(t->data);
        begin++;
    }
   levelsGrowing(t->left);
   levelsGrowing(t->right);

}


/*
======================
Тестове
======================
*/

// TEST_CASE("Test Edges") 
// {
//     box<int> *t=nullptr;

//     CHECK(levelsGrowing(t).size()==0);

//     setAt(t,"",10);

//     CHECK(levelsGrowing(t).size()==1);

// }


// TEST_CASE("Test Levels Growing") 
// {
//     box<int> *t=nullptr;

//     setAt(t,"",10);
//     setAt(t,"L",20);
//     setAt(t,"R",30);
//     setAt(t,"RL",40);
//     setAt(t,"RR",50);
//     setAt(t,"RRL",60);
//     setAt(t,"RLL",70);
//     setAt(t,"RRR",80);

//     std::vector<int> expected = {10, 30, 20, 80, 60, 70};
//     CHECK(expected==levelsGrowing(t));

// }


int main()
{
    box<int> *t=nullptr;

        setAt(t,"",10);
        setAt(t,"L",20);
        setAt(t,"R",30);
        setAt(t,"RL",40);
        setAt(t,"RR",50);
        setAt(t,"RRL",60);
        setAt(t,"RLL",70);
        setAt(t,"RRR",80);
        std::cout << count_elements_level(t,2);

        std::vector<int> test = levelsGrowing(t);
        for (int i: test)
        {
            std::cout << i << " ";
        }
        
    // doctest::Context().run();
}