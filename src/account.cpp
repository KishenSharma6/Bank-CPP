#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "../include/account.h"
#include "../include/frontEnd.h"
#include "../include/importExportData.h"
#include "../include/pin.h"


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
    srand(time(0));

    int acct_num = rand() % 89999 + 10000;
   
    /*verify acct_num does not exist already in accounts.txt*/
    verify_account(std::to_string(acct_num));
    if (verify_account(std::to_string(acct_num)) == 1)
    {
        return acct_num;
    }
    else // test to make sure this doesnt cause an infinite looop
        generate_account();
        return 0;
}

bool verify_account(std::string acct_number){
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
                if (token == acct_number)
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
int user_sign_in(std::string acct_num, std::string pin){
    

    /*verify acct_num and pin*/
    int user_attempts= 0;
    while (user_attempts != 3)
    {
        if (verify_account(acct_num) == false)
        {
            user_attempts ++;
            std::cout << "Incorrect account number, please re-enter your account number:" << std::endl;
            std::cin >> acct_num;
        }
        else
            break;
    }
    if (user_attempts == 3)
    {
        std::cout << "Too many attempts have been made, returning to main menu" << std::endl;
        welcome_menu();

    }

    user_attempts= 0;
    
    while (user_attempts != 3)
    {
        if (pin_verification(acct_num, pin) == false)
        {
            user_attempts ++;
            std::cout << "Incorrect pin, please re-enter your pin:" << std::endl;
            std::cin >> pin;
        }
        else
            break;
    }
    if (user_attempts == 3)
    {
        std::cout << "Too many attempts have been made, returning to main menu" << std::endl;
        welcome_menu();
    }

    std::cout << "Account and pin verified" << std::endl;
    return 0;
}


