#include <iostream>
#include "../include/transactions.h"

Account::Account(float x, std::string y){
    balance= x;
    bankName= y;
}
int Account::deposit(float amount){
    balance += amount;
    std::cout << "New Balance: " << balance << std::endl;
    return 0;
}

int Account::withdraw(float amount){
    balance -= amount;
    std::cout << "New Balance: " << balance << std::endl;
    return 0;
}

int Account::aboutAccount(){
    std::cout << "User has an account with " << bankName << " with a balance of $" << balance << std::endl;
    return 0;
}