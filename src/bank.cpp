#include <iostream>
#include "headers/bank.h"

class Account{
    private:
        float balance;
    
    public:
        std::string bankName;
        bool checking;

    Account(float x, std::string y, bool z){
        if (x < 0){
            std::cout << "Balance must be > 0" << std::endl;
        } else{
        balance= x;
        bankName= y;
        checking= z;
        };

    }

    ~Account();

    void Deposit(float amount){
        balance += amount;
    }

    float Withdrawal(float amount){
        if (amount < balance){
            balance -= amount;
            return amount;
        } else {
            std::cout << "Not enough funds in account"<< std::endl;
        };
    }

}