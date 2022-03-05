#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "../include/account.h"
#include "../include/frontEnd.h"
#include "../include/importExportData.h"
#include "../include/pin.h"

struct Account{
    std::string account_number;
    std::string pin;
};

int create_pin(){
    /*Create + verify pin from user*/
    std::cout << "Pins must be a 4 digit number" << std::endl;
    std::cout << "Please enter your pin now:" << std::endl;
    
    int unverified_pin= 0;
    int verified_pin= 0;

    std::cin >> unverified_pin;

    if (unverified_pin > 999 & unverified_pin <= 9999){
        verified_pin= verify_pin(unverified_pin);
        return verified_pin;
        
    } else{
        std::cout << "Incorrect pin, please try again" << std::endl;
        create_pin();
        return 0;
    };
};
int verify_pin(int unverified_pin){
    /*Verify pin was input correctly by user*/ 
    int pin= 0;
    std::cout << "Please verify pin:" << std::endl;
    std::cin >> pin;

    if (unverified_pin == pin){
        std::cout << "Pin verified" << std::endl;
        return pin;
    } else{
        std::cout << "Pin is unverified, please start again" << std::endl;
        create_pin();
        return 0;
    
    };

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