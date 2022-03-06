#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "../include/account.h"
#include "../include/frontEnd.h"
#include "../include/importExportData.h"
#include "../include/pin.h"
#include "../include/transactions.h"

struct Account{
    std::string account_number;
    std::string balance;
};

int deposit(){
    std::string acct_num;
    std::string pin;
    float deposit_amount = 0;

    std::cout << "Please enter your account number and your 4-digit pin:" << std::endl;
    std::cout << "Account Number:" << std::endl;
    std::cin >> acct_num;
    std::cout << "Pin Number:" << std::endl;
    std::cin >> pin;
    
    user_sign_in(acct_num, pin);
    
    std::cout << "Please enter your deposit amount: "<< std::endl;
    std::cin >> deposit_amount;

    std::string current_balance;

    
    return 0;
}

int withdraw(){
    return 0;
}

int print_receipt(){
    return 0;

}

std::string read_account_balance(std::string acct_num){
    /*Search account.txt to verify pin matches input account number*/
    std::ifstream database;
    std::vector<Account> accounts;
    std::string path = "/Users/ksharma/Documents/ML Engineer/Machine Learning/Projects/C++ Sandbox/Bank/data/accounts.txt";
    database.open(path, std::ios::in);
    if (database.is_open())
    {   
        std::string line;
        while(getline(database, line))
        {
            auto delimiter= line.find(',');
            if (delimiter != std::string::npos)
            {
                std::string account_number = line.substr(0, delimiter);
			    std::string pin = line.substr(delimiter+1, delimiter -1);
                std::string balance = line.substr(delimiter+1, delimiter -1);
                std::string first = line.substr(delimiter+1, delimiter -1);
                std::string last = line.substr(delimiter+1, delimiter -1);
			    Account account = { account_number, pin };
			    accounts.push_back(account);
            }
        }
    } 
    else  
        std::cout << "Error opening file";
    database.close();

    return "balance";
}