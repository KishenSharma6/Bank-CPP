
#include <iostream>
#include <fstream>
#include <sstream>

int write_user_data(std::string first, std::string last, int acct_num, float balance, int pin){
    /* 
    Collect & write user data
    Takes user inputs (first and last name, system generated account number, and pin)
    and saves then to accounts.txt for later access
    */
    std::ofstream outfile;
    std::string path = "/Users/ksharma/Documents/ML Engineer/Machine Learning/Projects/C++ Sandbox/Bank/data/accounts.txt";
    outfile.open(path, std::ios::app); // open file
    if (outfile.is_open()) //confirm file opened
    {
        outfile << acct_num << "," << pin << "," << balance << "," << first << "," << last << std::endl;
        outfile.close();       
    }
    else
        std::cerr << "Error writing to database";
    outfile.close();
    return 0;
    
}