#ifndef customer_h
#define customer_h

#include <iostream>

class Customer{
    private:
        int atm_pin= 1234;
    public:
        std::string name;
        

    Customer(int a, std::string b);

};
    
#endif