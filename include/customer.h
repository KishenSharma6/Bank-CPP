#ifndef customer_h
#define customer_h

#include <iostream>

class Customer{
    //private:
      //  int atm_pin;
    public:
        std::string name;
        std::string occupation;
        int age;

    Customer(std::string b, std::string c, int d);
    void introduction();

};
    
#endif