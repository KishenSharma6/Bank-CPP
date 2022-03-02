#ifndef machine_h
#define machine_h

#include <iostream>

void welcome_menu();
int write_user_data(std::string first, std::string last, int acct_num, float balance, int pin);
bool verify_account(std::string acct_number);
bool pin_verification(std::string acct_number, std::string pin);
int user_sign_in(std::string acct_num, std::string pin);
#endif