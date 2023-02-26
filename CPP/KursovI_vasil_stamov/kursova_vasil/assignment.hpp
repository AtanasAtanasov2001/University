#pragma once
#include "bank_account.hpp"
#include <unordered_map>
#include <algorithm>
#include <iterator>

class Assignment{
    private:
    std::vector<BankAccount*> accounts;

    public:
    Assignment() = default;
    Assignment(std::vector<BankAccount*> _accounts): accounts(_accounts){}
    ~Assignment(){}

    void create_file(){
        std::ofstream out("Accounts.txt");
        for (size_t i = 0; i < accounts.size(); i++)
        {
            accounts[i]->save_to_file("Accounts.txt");
        }
        std::ofstream outEnd("Accounts.txt", std::ofstream::app);
    }


    void print_names(std::vector<std::string> names) {
        std::cout << "The people that have more than one account are: "<< "\n";

        for (size_t i = 0; i < names.size(); i++)
        {
            std::cout << names[i] << "\n";
        }
        
    }
    void have_more_than_one_bank_account(){
        std::unordered_map<std::string, int> hash_table;
        std::vector<std::string> names;
        
        for(size_t i = 0; i < accounts.size(); i++) {
            if( hash_table.find(accounts[i]->get_ID()) != hash_table.end()){
                hash_table[accounts[i]->get_ID()] = hash_table.at(accounts[i]->get_ID()) + 1;
            }
            else {
                std::pair<std::string, int> to_insert (accounts[i]->get_ID(),1);
                hash_table.insert(to_insert);
            }
        }

        for (size_t i = 0; i < accounts.size(); i++)
        {
            if(hash_table.at(accounts[i]->get_ID()) > 1){
                names.push_back(accounts[i]->get_name());
            }
        }
        std::sort(names.begin(), names.end());
        std::vector<std::string>::iterator it = std::unique(names.begin(), names.end());
        names.resize(std::distance(names.begin(), it));

        print_names(names);
    }

    void difference_between_deposit_and_withdrawn(){
        
        for(size_t i = 0; i < accounts.size(); i++) {
            int difference = accounts[i]->get_deposited() - accounts[i]->get_withdrawn();
            std::cout << "The difference for the " << i << " account is: " << difference << "\n";
        }
    }

    void save_to_file_when_deposit_and_withdrawn_are_equal(){
        std::ofstream out("Equals.txt");
        for(size_t i = 0; i < accounts.size(); i++) {
            if(accounts[i]->get_deposited() == accounts[i]->get_withdrawn()) {
            
                accounts[i]->save_to_file("Equals.txt");
            }
        }
        std::ofstream outEnd("Equals.txt", std::ofstream::app);
    }
};