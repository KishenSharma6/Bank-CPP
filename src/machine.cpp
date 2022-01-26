#include "../include/machine.h"
#include "../include/transactions.h"

#include <iostream>

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