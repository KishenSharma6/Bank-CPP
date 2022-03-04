#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


struct Account{
    std::string account_number;
    std::string pin;
};



bool pin_verification(std::string input_acct_number, std::string input_pin){ 
    /*Search account.txt to verify pin matches input account number*/
    std::ifstream database;
    std::vector<Account> accounts;
    std::string path = "/Users/ksharma/Documents/ML Engineer/Machine Learning/Projects/C++ Sandbox/Bank/data/accounts.txt";
    database.open(path, std::ios::in);
    if (database.is_open())
    {   
        std::string line;
        while(getline(database, line))
        {
            auto delimiter= line.find(',');
            if (delimiter != std::string::npos)
            {
                std::string account_number = line.substr(0, delimiter);
			    std::string pin = line.substr(delimiter+1, delimiter -1);
			    Account account = { account_number, pin };
			    accounts.push_back(account);
            }
        }
    } 
    else  
        std::cout << "Error opening file";
    database.close();
    for (const Account &a: accounts)
    {
        if (a.account_number == input_acct_number && a.pin == input_pin)
        {
            return true;
        }
    }
    return false;
}