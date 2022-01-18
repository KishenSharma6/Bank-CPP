#include <iostream>
#include "../include/customer.h"
#include "../include/machine.h"

 Customer::Customer(std::string a){
    name= a;
    atm_pin= create_pin();
    std::cout << "New customer " << name << " created" << std::endl;

 }







