#include <iostream>
#include "string.hpp"
#include "employee.hpp"
#include "assignment.hpp"
int main(){



    // CharArray a1("abcdef", 7);
    // a1.print();
    std::string name("A");
    std::string s_name("Z");
    std::string t_name("A");
    std::string ID("1234567890");
    std::string code("ABCD");

    std::string name_1("G");
    std::string s_name_1("I");
    std::string t_name_1("S");
    std::string ID_1("1234567891");
    std::string code_1("ABCDE");

    std::string name_2("V");
    std::string s_name_2("H");
    std::string t_name_2("P");
    std::string ID_2("1234567892");
    std::string code_2("ABD");

    std::string name_3("T");
    std::string s_name_3("M");
    std::string t_name_3("M");
    std::string ID_3("1234567893");
    std::string code_3("AB");

    // CharArray a3;
    // a3 = a1 + a2;
    // a1.print();
    // a3.print();
    // a1 = a2;
    // a1.print();
    // std::cout << a1.validate();
    Employee e1(name, s_name, t_name, ID,code );
    Employee e2(name_1, s_name_1, t_name_1, ID_1,code_1 );
    Employee e3(name_2, s_name_2, t_name_2, ID_2,code_2 );
    Employee e4(name_3, s_name_3, t_name_3, ID_3,code_3 );


    std::vector<Employee> employees;
    employees.push_back(e1);
    employees.push_back(e2);
    employees.push_back(e3);
    employees.push_back(e4);

    Assignment a1(employees);

    a1.print_employees();
    a1.check_and_print();
    a1.save_to_file();
    return 0;
}