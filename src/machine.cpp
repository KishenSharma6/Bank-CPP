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



int create_pin(){
    std::cout << "Welcome customer! Please create a pin for your new checking account." << std::endl;
    std::cout << "Pins must be a 4 digit number" << std::endl;
    std::cout << "Please enter your pin now:" << std::endl;
    
    // create variable to hold pins for verification
    int unverified_pin= 0;
    int verified_pin= 0;

    std::cin >> unverified_pin;

    //Check if initial pin meets requirements
    if (unverified_pin > 999 & unverified_pin <= 9999){
        verified_pin= verify_pin(unverified_pin);
        return verified_pin;
        
    } else{
        std::cout << "Incorrect pin, please try again" << std::endl;
        create_pin();
        return 0;
    };
};

int verify_pin(int unverified_pin){
    // Verify customer correctly remembers pin
    int pin= 0;
    std::cout << "Please verify pin:" << std::endl;
    std::cin >> pin;

    if (unverified_pin == pin){
        std::cout << "Pin verified" << std::endl;
        return pin;
    } else{
        std::cout << "Pin is unverified, please start again" << std::endl;
        create_pin();
        return 0;
    
    };

};