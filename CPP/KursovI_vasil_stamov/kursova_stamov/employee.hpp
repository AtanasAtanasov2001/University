#include <iostream>
#include <string>
#include "string.hpp"
#include <fstream>
#pragma once

class Employee {
    private:
    std::string first_name;
    std::string second_name;
    std::string third_name;
    std::string ID;
    std::string code_for_occupation;

    public:
    Employee() = default;

    Employee(std::string _first_name,std::string _second_name,std::string _third_name,std::string _ID,std::string _code_for_occupaation ){    
        first_name = _first_name;
        second_name = _second_name;
        third_name = _third_name;
        ID = _ID;
        code_for_occupation = _code_for_occupaation; 
    }

    std::string get_code(){
        return this->code_for_occupation;
    }

    void save_to_file (std::string filename) {
        std::ofstream out(filename, std::ofstream::app);
        out << "First Name: " << first_name << " Second Name: " << second_name << " Third Name: "
        << third_name << " ID: "<< ID << " Code: " << code_for_occupation << '\n';
    }

    friend std::ostream& operator<<(std::ostream& out, const Employee& emp) {
        out << "First Name: " << emp.first_name << " Second Name: " << emp.second_name << " Third Name: "
        << emp.third_name << " ID: "<< emp.ID << " Code: " << emp.code_for_occupation << '\n';

        return out; 
    }


};
