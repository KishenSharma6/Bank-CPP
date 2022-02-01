#include "../include/machine.h"
// #include "../include/customer.h"
// #include "../include/transactions.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void welcome_menu(){
    int selection;
    do
    {
        std::cout << std::endl
        << "=====================================\n"
        << "Welcome to Sharma Credit Union\n"
        << "Please select an option from the menu below to get started:\n"
        << " 1 - Open new checking account.\n"
        << " 2 - Make withdrawal from account.\n"
        << " 3 - Make a deposit into your account. \n"
        << " 4 - Get your account balance. \n"
        << " 5 - Exit \n"
        << "=====================================\n"

        << "Enter your choice and press return: ";

        std::cin >> selection;

        switch(selection){
            case 1:
                //get_customer_info();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;  
        } 

    } while (selection <= 5);
    std::cout << "Thank you for stopping by Sharma Credit Union, good bye!" << std::endl;
}
int write_user_data(std::string first, std::string last, int acct_num, int pin){
    //write customer data to txt file
    // account number, first, last, balance, pin
    std::ofstream outfile;

    outfile.open("../data/accounts.txt", std::ios::app); // open file
    if (outfile.is_open()) //confirm file opened
    {
        outfile << acct_num << "," << pin << "," << first << "," << last << std::endl;
        outfile.close();       
    }
    else
        std::cerr << "Error writing to database";
    return 0;
    
}
bool verify_account(int acct_number){
    //Check if acct number exists in database
    std::fstream database;

    database.open("../data/accounts.txt", std::ios::in);
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
    return false;
}

bool pin_verification(int acct_number, int pin){ 
    //Check if pin is valid 
    std::fstream database;
    std::vector<std::string> tokens;

    database.open("../data/accounts.txt", std::ios::in);
    if (database.is_open())
    {   
        std::string line;
        while(getline(database, line))
        {   
            std::stringstream lineStream(line);
            std::string token;
            while(lineStream >> token)
            {
                tokens.push_back(token);
                //search for acct num in vector of tokens for line
            }
            
        }
    } 
    else  
        std::cout << "Error opening file";
    return false;
}