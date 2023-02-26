#include <iostream>
int main()
{
    int* a,b;
    b = 5;
    a =&b;
    *a += b;
    b--;
    std::cout << a;
    return 0;
}