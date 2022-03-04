#include "../include/frontEnd.h" 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
        << " 2 - Make a deposit into your account.\n"
        << " 3 - Make a withdrawal from your account. \n"
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