#ifndef transactions_h
#define transactions_h

#include <iostream>
   
// Account(float x, std::string y);
float deposit(float amount, float balance);
float withdraw(float amount, float balance);
void print_receipt();

#endif