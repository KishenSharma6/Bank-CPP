#include <iostream>
#include "../include/customer.h"
#include "../include/machine.h"



 void visit_bank(){
    std::cout << "Would you like to visit the ATM (Y/N)?" << std::endl;
    char response;
    std::cin >> response;

    while (toupper(response) != 'Y' | toupper(response) != 'N'){
        std::cout <<"Invalid response.\N Would you like to visit the ATM (Y/N)?:" << std::end;
        std::cin >> response;
        
        if (toupper(response) == 'N'){
            std::cout << "Have a nice day!" << std::endl;
        } else if (toupper(response) == 'Y'){
            //initiate welcome sequence from machine.cpp
            //welcome();
            break;
        }

    }
 }







