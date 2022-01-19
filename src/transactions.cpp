#include <iostream>
#include "../include/transactions.h"

// Account::Account(float x, std::string y){
//     balance= x;
//     bankName= y;
// }
float deposit(float amount, float balance){
    balance += amount;
    print_receipt(balance);
    return balance;
}

float withdraw(float amount, float balance){
    balance -= amount;
    print_receipt(balance);
    return balance;
}

void print_receipt(float balance){
    std::cout << "New Balance: " << balance << std::endl;

}