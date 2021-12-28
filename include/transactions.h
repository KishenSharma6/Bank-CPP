#ifndef transactions_h
#define transactions_h

#include <iostream>
//contain function/class declaration
class Account{
public:
    float balance;
    
    Account(float x);
    int deposit(float amount);

    int withdraw(float amount);
};
#endif