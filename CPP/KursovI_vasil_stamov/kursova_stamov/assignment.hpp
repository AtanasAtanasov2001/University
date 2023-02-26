#include <iostream>
#include "employee.hpp"
#include <vector>

class Assignment {
    private:
    std::vector<Employee> employees;

    public:

    Assignment() = default;
    Assignment(std::vector<Employee> _employees) : employees(_employees){}
    ~Assignment(){};

    void print_employees(){
        for(size_t i = 0; i < employees.size(); i++){
            std::cout << employees[i] << '\n';
        }
    }

    void check_and_print(){
        std::cout << "The employees who have adequate work(code) are: " << '\n';
        for (size_t i = 0; i < employees.size(); i++)
        {
            if(employees[i].get_code().size() <= 4){
                std::cout << employees[i];
            }
        }
        
    }

    void save_to_file(){
        std::ofstream out("Employees.txt");

        for (size_t i = 0; i < employees.size(); i++)
        {
            employees[i].save_to_file("Employees.txt");
        }
        std::ofstream outEnd("Employees.txt", std::ofstream::app);
    }
};