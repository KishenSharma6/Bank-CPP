#include <iostream>
#include "../include/customer.h"
#include "../include/machine.h"

 Customer::Customer(std::string a){
     
    name= a;
    int verified_pin= create_pin();
    atm_pin= verified_pin;

    std::cout << "New customer " << name << " created" << std::endl;

 }







