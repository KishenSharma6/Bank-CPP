#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "../include/account.h"
#include "../include/frontEnd.h"
#include "../include/importExportData.h"
#include "../include/pin.h"
#include "../include/transactions.h"
#include "../include/machine.h"

<<<<<<< HEAD
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

    
=======
int deposit(){
    /*Deposit funds into user's account*/
    int user_acct = 0;
    std::cout << "Please enter your 5-digit account number: " << std::endl;
    std::cin >> user_acct;

    /*Verify this account exists*/
    if (verify_account(user_acct) == 0)
    {
        std::cout<< "Incorrect account number" << std::endl;
        deposit();       
    }
    /*Verify pin*/
    int user_pin= 0;
    std::cout << "Please enter your 4-digit pin:" << std::endl;
    std::cin >> user_pin;

    if (pin_verification(std::to_string(user_acct), std::to_string(user_pin)) == 0)
    {
        std::cout << "Pin is incorrect. Make sure you have the correct account number and try again" << std::endl;
        deposit();
    }

    /* Get deposit amount from user*/
    float deposit_amount= 0.00;

>>>>>>> f72b61449f1e31697b575c50c17685f1a9bf6289
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