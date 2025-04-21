#include<iostream> 
using namespace std; 

class BankAccount { 
    private: 
    string accountNumber;
    string ownerName;
    double balance;

    public: 
    BankAccount(const string& accountNumber, const string& ownerName, double balance);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    void displayAccount() const;
};