#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "../include/customer.h"
#include "../include/machine.h"

// should we init a customer object that holds name, DOB, and pin? how else can we store this data?
 int get_customer_info(){
     //Get Customer Name + Pin
    std::string first_name;
    std::string last_name;
    int acct_number = generate_account();
    int pin= 1234;
         
    std::cout << "Before we can begin opening your new checking account, tell us about yourself"<< std::endl;
    std::cout << "What is your first name? \n" << std::endl;
    std::cin >> first_name;

    std::cout << "What is your last name?\n" << std::endl;
    std::cin >> last_name;

    std::cout << "Thank you and welcome to Sharma Credit Union " << first_name << std::endl;
    std::cout << "Your new account number is "<< acct_number << std::endl;

    std::cout << "Finally, we need to create a pin for your account" << std::endl;
    pin= create_pin();
    
    std::cout << "Your account set up has been completed, we will return you to the main menu" << std::endl;
 }

int generate_account(){
    //Generate random Account number for user
        // Checks database to make sure no duplicate account numbers are issued

    int acct_num;
    srand(time(0));

    acct_num = rand() % 89999 + 10000;
    //make sure acc_num does not exist in data base
    verify_account(acct_num);
    if (verify_account(acct_num) == 0)
    {
        return acct_num;
    }
    else // test to make sure this doesnt cause an infinite looop
        generate_account();

}


   
int create_pin(){
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
