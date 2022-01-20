#include <iostream>
#include <ctime>

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
    std::string first_name;
    std::string last_name;
         
    std::cout << "Before we can begin opening your new checking account, tell us about yourself"<< std::endl;
    std::cout << "What is your first name? \n" << std::endl;
    std::cin >> first_name;

    std::cout << "What is your last name?\n" << std::endl;
    std::cin >> last_name;


    return 0;
 }

