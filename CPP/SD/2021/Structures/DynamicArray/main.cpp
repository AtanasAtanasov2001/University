#include <iostream>
#include "DyamicArray.h"

class Student
{
    public:
    int fn;
    void Displayfn()
    {
        std::cout << fn << '\n';
    }

    Student()
    {
        std::cout << "Student is being created..."<< '\n';
    }
    ~Student()
    {
        fn = 0;
    }
};

int main()
{

//    /*Student ... type*/ void* student = (void*) (operator new(sizeof(Student) * 1));

//     //placement new syntax
//     new((void*) student) Student();
    
//     // (static_cast<Student*> (student))-> ~Student(); -> вместо да се прави пойнтър!!!

//     //ако нямаме указан тип, подсигуряваме генерична памет, за конструиране!!


//     //тъй като student e void* => че е generic type => няма как да достъпи методите/член-данните
//     // на обекта. Следва да пренасочим нов пойнтър към тази памет, който да успява да достъпи 
//     //елементите и съответно да се изтрие правилно обекта
//     Student* studentPointer = static_cast<Student*>(student);

//     //{int* studentPointer = static_cast<int*>(student);}-> променливата се изтрива автоматично след приключване на scope-a({})
//     //в случая ако не искаме да се пълни стека  
    
//     studentPointer->~Student();
//     operator delete(studentPointer);

//     delete student;
try{
        // DynamicArray<int> d;

        // d.push_back(3);
        // d.push_back(4);
        // d.push_back(5);
        // d.push_back(6);
        // d.push_back(7);

        // d.print();
        // DynamicArray<int> d2;
        // d2 = d;
        // //std::cout << d.capacity;
        // //std::cout << d[2] << "\n";
        // d[3] = 5;
        // d.print(); 
        // // DynamicArray<int> c(d);
        // // c[1]=9;
        // // std::cout << (c == d) << "\n";
        // d.pop_up();
        // d.print();
        // d.pop_desired(1);
        // d.print();
        // d.resize(2);
        // d.print();
        // d.reserve(5);
        // d.print(); 

        // DynamicArray<Student*> s;
        // Student k;
        // k.fn = 123;
        // Student m;
        // m.fn = 321;
        // std::cout << "cap: " << s.capacity << std::endl;
        // s.push_back(&k);
        // std::cout << "cap: " << s.capacity << std::endl;
        // s.push_back(&m);
        // s.push_back(&m);

        // std::cout << s[0]->fn << " "<< s[1]->fn << std::endl;
        // std::cout <<s.size <<"cap" <<s.capacity << "\n";
    }catch(std::exception& k){
        std::cout << k.what();
    }
    return 0;
}