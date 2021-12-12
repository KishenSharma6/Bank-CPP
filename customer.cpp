#include <iostream>
#include <string>

class Customer{
    private:
        int wallet;
    public:
        std::string name;
        int age;
    
        Customer(int x, std::string y, int z){
            //Constructor
            wallet = x;
            name = y;
            age= z;

        }

        void Deposit(float amount){
            wallet -= amount;
        }

        void Withdrawal(float amount){
            wallet += amount;
        }



};