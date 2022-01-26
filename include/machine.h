#ifndef machine_h
#define machine_h

#include <iostream>

void welcome_menu();
int write_user_data(std::string first, std::string last, int acct_num, int pin);
bool verify_account(int acct_number);
bool pin_verification(int acct_number, int pin);

#endif