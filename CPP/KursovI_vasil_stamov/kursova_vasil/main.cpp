#include "bank_account.hpp"
#include "assignment.hpp"
#include <numeric>

int main(){

    std::pair<char, int> unique_code_1{'A',00000};
    std::vector<int> deposited_sum_1 {3000,4300,234,1345,5000,15000};
    std::vector<int> withdrawn_sum_1 {2000,200,144,1222,100,50,100,150,600,340,255,1000};
    
    BankAccount * a1 = new BankAccount(unique_code_1, "Georgi Georgiev", "1122334455", deposited_sum_1, withdrawn_sum_1, 
        std::accumulate(deposited_sum_1.begin(),deposited_sum_1.end(), 0),std::accumulate(withdrawn_sum_1.begin(),withdrawn_sum_1.end(), 0) );

    std::pair<char, int> unique_code_2{'B',00001};
    std::vector<int> deposited_sum_2 {1200,300,234,500,1500,1000};
    std::vector<int> withdrawn_sum_2 {1200,300,234,500,1500,1000};

    BankAccount * a2 = new BankAccount(unique_code_2, "Dimitar Dimitrov", "1122331122", deposited_sum_2, withdrawn_sum_2, 
        std::accumulate(deposited_sum_2.begin(),deposited_sum_2.end(), 0),std::accumulate(withdrawn_sum_2.begin(),withdrawn_sum_2.end(), 0) );

    std::pair<char, int> unique_code_3{'C',00002};
    std::vector<int> deposited_sum_3 {1200,300,234,3000,100,432,2000,4321,600};
    std::vector<int> withdrawn_sum_3 {300,200,130,40,55,110};

    BankAccount * a3 = new BankAccount(unique_code_3,  "Georgi Georgiev", "1122334455", deposited_sum_3, withdrawn_sum_3, 
        std::accumulate(deposited_sum_3.begin(),deposited_sum_3.end(), 0),std::accumulate(withdrawn_sum_3.begin(),withdrawn_sum_3.end(), 0) );


    std::pair<char, int> unique_code_4{'D',00003};
    std::vector<int> deposited_sum_4 {2000,350,1110,5420,400,1220,10000,7500};
    std::vector<int> withdrawn_sum_4 ;

    BankAccount* a4 = new BankAccount(unique_code_4, "Dimitar Dimitrov", "1122331122", deposited_sum_4, withdrawn_sum_4, 
        std::accumulate(deposited_sum_4.begin(),deposited_sum_4.end(), 0),std::accumulate(withdrawn_sum_4.begin(),withdrawn_sum_4.end(), 0) );


    std::vector<BankAccount*> accounts;
    accounts.push_back(a1);
    accounts.push_back(a2);
    accounts.push_back(a3);
    accounts.push_back(a4);

    // std::ofstream out("Bank.txt");
    
    // for (size_t i = 0; i < accounts.size(); i++)
    // {
    //     accounts[i]->save_to_file("Bank.txt");
    // }


    Assignment* assignment = new Assignment(accounts);
    assignment->create_file();
    assignment->difference_between_deposit_and_withdrawn();
    assignment->have_more_than_one_bank_account();
    assignment->save_to_file_when_deposit_and_withdrawn_are_equal();


    return 0;
}