#include <iostream>
#include "../include/transactions.h"
#include "../include/customer.h"

int main(){
    Customer cust1(1234,"Chad", "Engineer", 31);
    cust1.introduction();
    Account acct1(15.11, "Wells Fargo"); 
    acct1.deposit(100);
    acct1.aboutAccount();
    return 0;
}