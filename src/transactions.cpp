#include <iostream>
#include "../include/transactions.h"
#include "../include/machine.h"

int deposit(){
    /*Deposit funds into user's account*/
    int user_acct = 0;
    std::cout << "Please enter your 5-digit account number: " << std::endl;
    std::cin >> user_acct;

    /*Verify this account exists*/
    if (verify_account(user_acct) == 0)
    {
        std::cout<< "Incorrect account number" << std::endl;
        deposit();
    }
    /*Verify pin*/
    int user_pin= 0;
    std::cout << "Please enter your 4-digit pin:" << std::endl;
    std::cin >> user_pin;

    if (pin_verification(std::to_string(user_acct), std::to_string(user_pin)) == 0)
    {
        std::cout << "Pin is incorrect. Make sure you have the correct account number and try again" << std::endl;
        deposit();
    }

    /* Get deposit amount from user*/
    float deposit_amount= 0.00;

    return 0;
}

int withdraw(){
    return 0;
}

int print_receipt(){
    return 0;

}