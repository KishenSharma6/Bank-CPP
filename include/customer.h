#ifndef customer_h
#define customer_h

#include <iostream>

class Customer{
    private:
        int atm_pin= 1234;
    public:
        std::string name;
        float wallet = 0.00;
        

    Customer(std::string a, float b);
    void visit_bank();


};
    
#endif