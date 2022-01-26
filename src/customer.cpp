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

    return 0;
 }

int generate_account(){
    //Generate randome Account number for user
    //Check to make sure this doesn't exist in database!!!

    int acct_num;
    srand(time(0));

    acct_num = rand() % 89999 + 10000;
    std::cout<< acct_num;
    return acct_num;

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
