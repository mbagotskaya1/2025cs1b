#include<iostream> 
#include "p5.h"
using namespace std; 

BankAccount::BankAccount(const string& accountNumber, const string& ownerName, double balance) : accountNumber(accountNumber), ownerName(ownerName), balance(balance < 0 ? 0.0 : balance) {}
void BankAccount::deposit(double amount) {
    if (amount < 0) {
        cout << "deposit amount should be positive" << endl;
    }
    else {
        balance += amount;
        cout << "deposited: " << amount << endl;
    }
}
bool BankAccount::withdraw(double amount) {
    if (amount < 0) {
        cout << "withdrawal amount should be positive" << endl;
        return false;
    }
    if (amount <= balance) {
        balance -= amount;
        cout << "withdrawed: " << amount << endl;
        return true;
    }
    else {
        cout << "insufficent balance" << endl;
        return false;
    }
}
double BankAccount::getBalance() const {
    return 0;
}
void BankAccount::displayAccount() const{
    cout << "Account number: " << accountNumber << " Owner's name: " << ownerName << " Current balance: " << balance << endl; 
}