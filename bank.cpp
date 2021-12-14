#include <iostream>

class Account{
    private:
        float balance;
    
    public:
        std::string bankName;
        bool checking;

    Account(float x, string y, bool z){
        balance= x;
        bankName= y;
        checking= z;

    }

    void Deposit(float amount){
        balance += amount;
    }

    float Withdrawal(float amount){
        if (amount < balance){
            balance -= amount;
            return amount
        } else {
            std::cout << "Not enough funds in account"<< std::endl;
        };
    }

}