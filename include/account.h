#ifndef account_h
#define account_h

#include <iostream>

int get_customer_info();
int generate_account();
bool verify_account(std::string acct_number);
int user_sign_in(std::string acct_num, std::string pin);

#endif