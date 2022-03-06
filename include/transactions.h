#ifndef transactions_h
#define transactions_h

#include <iostream>

// Account(float x, std::string y);
int deposit();
int withdraw();
int print_receipt();
std::string read_account_balance(std::string acct_num);

#endif