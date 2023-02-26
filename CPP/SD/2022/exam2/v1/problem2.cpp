#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"
#include "../treeutils.cpp"

#include <vector>

/*
======================
Решение на задачата:
======================
*/



/*
======================
Тестове
======================
*/
TEST_CASE("Edges") 
{
    box<int> *t=nullptr;

    CHECK(levelsReverse(t).size()==0);

    setAt(t,"",10);

    std::vector<int> expected = {10};
    CHECK(expected==levelsReverse(t));

}


TEST_CASE("Test Levels Reverse") 
{
    box<int> *t=nullptr;

    setAt(t,"",10);
    setAt(t,"L",20);
    setAt(t,"R",30);
    setAt(t,"RL",40);
    setAt(t,"RR",50);
    setAt(t,"RRL",60);

    std::vector<int> expected = {60, 50, 40, 30, 20, 10};
    CHECK(expected==levelsReverse(t));

}


int main()
{
    doctest::Context().run();
}