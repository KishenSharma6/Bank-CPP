#include <iostream>
#include "../include/customer.h"

 Customer::Customer(std::string b, std::string c, int d){
     //atm_pin= a;
     name= b;
     occupation= c;
     age= d;
 }

void Customer::introduction(){
    std::cout<< "Name: "<< name<< "\nOccupation: "<< occupation << "\nAge: " << age << std::endl;
}





