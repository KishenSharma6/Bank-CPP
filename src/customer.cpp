#include <iostream>
#include "../include/customer.h"
#include "../include/machine.h"

 Customer::Customer(std::string a, float b){
     
    name= a;
    wallet = b;
    int verified_pin= create_pin();
    atm_pin= verified_pin;

    

 }

 void Customer::visit_bank(){
    std::cout << "Would  " << name << " like to visit the ATM (Y/N)?" << std::endl;
    char response;
    std::cin >> response;

    while (toupper(response) != 'Y' | toupper(response) != 'N'){
        std::cout <<"Invalid response.\N Would you like to visit the ATM (Y/N)?:" << std::end;
        std::cin >> response;
        
        if (toupper(response) == 'N'){
            std::cout << "Have a nice day " << name << " !" << std::endl;
        } else if (toupper(response) == 'Y'){
            //initiate welcome sequence from machine.cpp
            //welcome();
            break;
        }

    }
 }







