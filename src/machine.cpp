#include "../include/machine.h"
#include "../include/transactions.h"

#include <iostream>
#include <fstream>

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
                create_pin();
                break;
            case 2:
                withdraw();
                break
                
            

        } 

    } while (selection <= 5);

}

int write_user_data(std::string first, std::string last, int acct_num, int pin){
    //write customer data to txt file
    // account number, first, last, balance, pin
    std::ofstream outfile;

    outfile.open("../data/accounts.txt", std::ios::app); // open file
    if (outfile.is_open()) //confirm file opened
    {
        outfile << acct_num;
        outfile.close();
        
    }
    else
        std::cerr << "Error writing to database";
    
}
