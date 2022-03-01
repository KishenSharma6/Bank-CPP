#include "../include/machine.h" 
#include "../include/customer.h"
#include "../include/transactions.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Account{
    std::string account_number;
    std::string pin;
} ;

void welcome_menu(){
    /* 
    Front End Menu
    Takes user input and executes appropriate function.
    */
    int selection;
    do
    {
        std::cout << std::endl
        << "=====================================\n"
        << "Welcome to Sharma Credit Union\n"
        << "Please select an option from the menu below to get started:\n"
        << " 1 - Open new checking account.\n"
        << " 2 - Make deposit into your account.\n"
        << " 3 - Make a withdrawal from your account. \n"
        << " 4 - Get your account balance. \n"
        << " 5 - Exit \n"
        << "=====================================\n"

        << "Enter your choice and press return: ";

        std::cin >> selection;

        switch(selection){
            case 1:
                get_customer_info();
                break;
            case 2:
                deposit();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;  
        } 

    } while (selection < 5);
    std::cout << "Thank you for stopping by Sharma Credit Union, good bye!" << std::endl;
}
int write_user_data(std::string first, std::string last, int acct_num, int pin){
    /* 
    Collect & write user data
    Takes user inputs (first and last name, system generated account number, and pin)
    and saves then to accounts.txt for later access
    */
    std::ofstream outfile;
    std::string path = "/Users/ksharma/Documents/ML Engineer/Machine Learning/Projects/C++ Sandbox/Bank/data/accounts.txt";
    outfile.open(path, std::ios::app); // open file
    if (outfile.is_open()) //confirm file opened
    {
        outfile << acct_num << "," << pin << "," << first << "," << last << std::endl;
        outfile.close();       
    }
    else
        std::cerr << "Error writing to database";
    outfile.close();
    return 0;
    
}
bool verify_account(int acct_number){
    /*
    Returns true if system generated account number already exists in accounts.txt.
    */
    std::fstream database;
    std::string path= "/Users/ksharma/Documents/ML Engineer/Machine Learning/Projects/C++ Sandbox/Bank/data/accounts.txt";
    database.open(path, std::ios::in);
    if (database.is_open())
    {   
        std::string line;
        while(getline(database, line))
        {   
            std::stringstream lineStream(line);
            std::string token;
            while(lineStream >> token)
            {
                if (std::stoi(token) == acct_number)
                {
                    return true;
                    break;
                }
            }
        }
    } 
    else  
        std::cout << "Error opening file";
    database.close();
    return false;
}

bool pin_verification(std::string input_acct_number, std::string input_pin){ 
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
			    Account account = { account_number, pin };
			    accounts.push_back(account);
            }
        }
    } 
    else  
        std::cout << "Error opening file";
    database.close();
    for (const Account &a: accounts)
    {
        if (a.account_number == input_acct_number && a.pin == input_pin)
        {
            return true;
        }
    }
    return false;
}