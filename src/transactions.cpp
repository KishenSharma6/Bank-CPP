#include <iostream>
#include "../include/transactions.h"

Account::Account(float x){
    balance= x;
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