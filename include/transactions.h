#ifndef transactions_h
#define transactions_h

#include <iostream>

// Account(float x, std::string y);
int deposit(float amount);
int withdraw(float amount);
void print_receipt(float balance);

#endif