#include "../include/machine.h"
#include <iostream>

int create_pin(){
    std::cout << "Welcome customer! Please create a pin for your new checking account." << std::endl;
    std::cout << "Pins must be a 4 digit number" << std::endl;
    std::cout << "Please enter your pin now:" << std::endl;
    
    // create variable to hold pins for verification
    int unverified_pin= 0;
    int verified_pin= 0;

    std::cin >> unverified_pin;

    //Check if initial pin meets requirements
    if (unverified_pin > 999 & unverified_pin <= 9999){
        verified_pin= verify_pin(unverified_pin);
        return verified_pin;
        
    } else{
        std::cout << "Incorrect pin, please try again" << std::endl;
        create_pin();
    };
};

int verify_pin(int unverified_pin){
    // Verify customer correctly remembers pin
    int pin= 0;
    std::cout << "Please verify pin:" << std::endl;
    std::cin >> pin;

    if (unverified_pin == pin){
        std::cout << "Pin verified" << std::endl;
        return pin;
    } else{
        std::cout << "Pin is unverified, please start again" << std::endl;
        create_pin();
    };

};