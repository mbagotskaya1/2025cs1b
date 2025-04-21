#include<iostream> 
#include "p5.h"
using namespace std; 

int main() {
    BankAccount account("A0001", "John", 100);
    account.displayAccount();
    account.deposit(-100);
    account.displayAccount();
    account.deposit(500);
    account.displayAccount();
    account.withdraw(300);
    account.displayAccount();
}