#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#pragma once


class BankAccount {
    private:
    std::pair<char,int> unique_code;
    std::string name;
    std::string ID;
    std::vector<int> deposited_sum;
    std::vector<int> withdrawn_sum;
    float deposited; // the sum of the elements in the vector dep
    float withdrawn; // the sum of the elements in the vector with

    public:
    BankAccount() = default;

    BankAccount(std::pair<char, int> _uniquie_code, std::string _name,std::string _ID, std::vector<int> _deposited_sum, std::vector<int> _withdrawn_sum, float _deposited, float _withdrawn) :
    unique_code(_uniquie_code), name(_name),ID(_ID), deposited_sum(_deposited_sum), withdrawn_sum(_withdrawn_sum) ,deposited(_deposited), withdrawn(_withdrawn) {}

    ~BankAccount(){
        deposited = 0;
        withdrawn = 0;
        //std::pair and std::vector will be deleted automatically
    }
    float get_deposited(){
        return this->deposited;
    }
    float get_withdrawn(){
        return this->withdrawn;
    }
    std::string get_name(){
        return this->name;
    }
    std::string get_ID(){
        return this->ID;
    }

    void save_to_file(std::string filename) {
        std::ofstream out(filename, std::ofstream::app);
        out << "Unique Code: " << unique_code.first << " " << unique_code.second << " Name: " << name << " ID: "<< ID <<" "
        << " Deposited sum: " << deposited << " Withdrawn sum: " <<  withdrawn << "\n" ;

    }
    friend std::ostream& operator<< (std::ostream& out, const BankAccount& account){
        out << "Unique Code: " << account.unique_code.first << " " << account.unique_code.second << " Name: " << account.name << " ID: "<< account.ID <<" "
        << " Deposited sum: " << account.deposited << " Withdrawn sum: " <<  account.withdrawn << "\n" ;

        return out;
    }
};
