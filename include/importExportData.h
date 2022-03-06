#ifndef importExportData_h
#define importExportData_h

#include <iostream>

int write_user_data(std::string first, std::string last, int acct_num, float balance, int pin);
//int update_user_data(std::string first, std::string last, int acct_num, float balance, int pin);
int read_user_data();
#endif
