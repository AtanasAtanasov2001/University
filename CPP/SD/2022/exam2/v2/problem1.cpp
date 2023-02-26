// #define DOCTEST_CONFIG_IMPLEMENT
// #include "../doctest.h"
#include <iostream>
#include "../treeutils.cpp"
#include <vector>

/*
======================
Решение на задачата:
======================
*/
template<typename T>
void expand(box<T>* t1, box<T>* t2){

    if(t1 == nullptr){
        return;
    }
    if(t2 == nullptr && t1 != nullptr){
        t2 = t1;
        return;
    }
    if(t2->left != nullptr || t2->right != nullptr) {
        std::cout << "enter if \n";
        std::cout << t1->data;
        if(t1 != nullptr) {
            t2 = new box<T> {t1->data, nullptr, nullptr};
        }
    }
    return expand(t1->left, t2->left);
    return expand(t1->right, t2->right);
}



/*
======================
Тестове
======================
*/
// TEST_CASE("Test Edges")
// {
//      box<int> *t1=nullptr,
//               *t2=nullptr,
//               *t3=nullptr;

//     setAt(t1,"",0);
//     setAt(t3,"",0);

//     expand(t2,t1);
//     CHECK(tree_equals(t1,t3));

//     expand(t1,t2);
//     CHECK(tree_equals(t2,t1));
   
// }

// TEST_CASE("Test Expand") 
// {
//     box<int> *t1=nullptr,
//              *t2=nullptr,
//              *t3=nullptr;

//     setAt(t1,"",10);
//     setAt(t1,"L",20);
//     setAt(t1,"R",30);
//     setAt(t1,"RL",40);
//     setAt(t1,"RLL",70);
//     setAt(t1,"RR",50);
//     setAt(t1,"RRL",60);

//     setAt(t2,"",0);
//     setAt(t2,"R",0);
//     setAt(t2,"RL",80);
//     setAt(t2,"RLL",90);
//     setAt(t2,"RLR",95);

//     setAt(t3,"",0);
//     setAt(t3,"R",0);
//     setAt(t3,"RL",80);
//     setAt(t3,"RLL",90);
//     setAt(t3,"RLR",95);
//     setAt(t3,"L",20);
//     setAt(t3,"RR",50);
//     setAt(t3,"RRL",60);

//     expand(t1,t2);
//     CHECK(tree_equals(t2,t3));

// }

// error with doctest!

int main()
{
     box<int> *t1=nullptr,
              *t2=nullptr,
              *t3=nullptr;

    setAt(t1,"",0);
    setAt(t3,"",0);

    expand(t2,t1);
    std::cout << std::boolalpha << tree_equals(t1,t3) << '\n';

    expand(t1,t2);
    std::cout << std::boolalpha << tree_equals(t2,t1)<< '\n';

    box<int> *t4=nullptr,
             *t5=nullptr,
             *t6=nullptr;

    setAt(t4,"",10);
    setAt(t4,"L",20);
    setAt(t4,"R",30);
    setAt(t4,"RL",40);
    setAt(t4,"RLL",70);
    setAt(t4,"RR",50);
    setAt(t4,"RRL",60);

    setAt(t5,"",0);
    setAt(t5,"R",0);
    setAt(t5,"RL",80);
    setAt(t5,"RLL",90);
    setAt(t5,"RLR",95);

    setAt(t6,"",0);
    setAt(t6,"R",0);
    setAt(t6,"RL",80);
    setAt(t6,"RLL",90);
    setAt(t6,"RLR",95);
    setAt(t6,"L",20);
    setAt(t6,"RR",50);
    setAt(t6,"RRL",60);

    expand(t4,t5);
    std::cout << std::boolalpha << tree_equals(t5,t6)<< '\n';

    return 0;
    // doctest::Context().run();
}