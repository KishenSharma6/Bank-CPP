#include <iostream>
#include <fstream>

#include "../include/customer.h"
#include "../include/machine.h"

// void visit_bank(){
//     std::cout << "Would you like to visit the ATM (Y/N)?" << std::endl;
//     char response;
//     std::cin >> response;

//     while (toupper(response) != 'Y' | toupper(response) != 'N'){
//         std::cout <<"Invalid response.\N Would you like to visit the ATM (Y/N)?:" << std::end;
//         std::cin >> response;
        
//         if (toupper(response) == 'N'){
//             std::cout << "Have a nice day!" << std::endl;
//         } else if (toupper(response) == 'Y'){
//             welcome_menu();
//             break;
//         }

//     }
//  }


// should we init a customer object that holds name, DOB, and pin? how else can we store this data?
 int get_customer_info(){
     //Get Customer Name + Pin
    std::string first_name;
    std::string last_name;
    int acct_number = generate_account();
    int pin= 1234;
         
    std::cout << "Before we can begin opening your new checking account, tell us about yourself"<< std::endl;
    std::cout << "What is your first name? \n" << std::endl;
    std::cin >> first_name;

    std::cout << "What is your last name?\n" << std::endl;
    std::cin >> last_name;

    std::cout << "Thank you and welcome to Sharma Credit Union " << first_name << std::endl;
    std::cout << "Your new account number is "<< acct_number << std::endl;

    std::cout << "Finally, we need to create a pin for your account" << std::endl;

    return 0;
 }

int generate_account(){
    //Generate randome Account number for user
    //Check to make sure this doesn't exist in database!!!

    int acct_num;
    srand(time(0));

    acct_num = rand() % 89999 + 10000;
    std::cout<< acct_num;
    return acct_num;

}


int write_user_data(std::string first, std::string last, int acct_num, int pin){
    //write customer data to txt file
    // account number, first, last, balance, pin
    std::ofstream outfile;

    outfile.open("../data/accounts.txt", std::ios::app); // open file
    if (outfile.is_open()) //confirm file opened
    {
        outfile << acct_num;
        outfile.close();
        
    }
    else
        std::cerr << "Error writing to database";
    
}
    
