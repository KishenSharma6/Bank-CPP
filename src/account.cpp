#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "../include/customer.h"
#include "../include/machine.h"

// should we init a customer object that holds name, DOB, and pin? how else can we store this data?
 int get_customer_info(){
    /*
    Get customer info: first, last, and pin
    */
    std::string first_name;
    std::string last_name;
    float init_deposit;
    int acct_number = generate_account();
    int pin= 12345;
         
    std::cout << "Before we can begin opening your new checking account, a $25.00 minimum deposit is required upon activation" << std::endl;
    std::cout << "How much would you like your initial deposit for your new account to be?" << std::endl;
    std::cin >> init_deposit;
    if (init_deposit < 25.00)
    {
        std::cout << "\nWe're sorry, you do not meet the minimum initial deposit criteria. \nReturning you to the main menu.\n" << std::endl;
        welcome_menu();
    }
    // tell us about yourself"<< std::endl;
    std::cout << "Thank you, before we can open your new checking account we need a little more information about you" <<std::endl;
    std::cout << "What is your first name?" << std::endl;
    std::cin >> first_name;

    std::cout << "What is your last name?" << std::endl;
    std::cin >> last_name;

    std::cout << "Thank you and welcome to Sharma Credit Union " << first_name << std::endl;
    std::cout << "\nYour new account number is "<< acct_number << std::endl;

    std::cout << "\nFinally, we need to create a pin for your account" << std::endl;
    pin= create_pin();
    
    std::cout << "\nYour account set up has been completed, we will return you to the main menu \n" << std::endl;

    /*Write customer data to accounts.txt*/
    write_user_data(first_name, last_name, acct_number, init_deposit,  pin);
    return 0;
 }
int generate_account(){
    /*Randomly generate account number for user*/
    int acct_num;
    srand(time(0));

    acct_num = rand() % 89999 + 10000;
    /*verify acct_num does not exist already in accounts.txt*/
    verify_account(acct_num);
    if (verify_account(acct_num) == 0)
    {
        return acct_num;
    }
    else // test to make sure this doesnt cause an infinite looop
        generate_account();
    return 0;
}
