#ifndef pin_h
#define pin_h

#include <iostream>

int create_pin();
int verify_pin(int unverified_pin);
bool pin_verification(std::string input_acct_number, std::string input_pin);

#endif