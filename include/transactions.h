#ifndef transactions_h
#define transactions_h

#include <iostream>
//contain function/class declaration
class Account{
public:
    float balance;
    std::string bankName;
    
    // Account(float x, std::string y);
    int deposit(float amount);

    int withdraw(float amount);

    void print_receipt();

};
#endif