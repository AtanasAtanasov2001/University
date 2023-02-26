#include "LList.cpp"
#include <iostream>

int main(){

    LList<int> kur;
    kur.push(1);
    kur.push(2);
    kur.push(3);
    kur.push(4);

    LList<int> chep = kur;

    kur.push(6);
    chep.push(9);
    kur.print();

    chep.print();
    chep.pop();
    chep.print();
    std::cout << chep.top().data << "\n";
    std::cout << chep.size();
    return 0;
}