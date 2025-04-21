#include<iostream> 
using namespace std; 

class BankAccount { 
    public: 
    BankAccount(double balance, const string& accountHolder = "") { 
        this->balance = balance; 
    } 

    void setAccountHolder(const string& accountHolder) { 
        this->accountHolder = accountHolder; 
    }

    double getBalance() const { 
        return this->balance; 
    }

    bool compare(const BankAccount& other) const { 
        return this->balance > other.balance; 
    }

    private: 
    string accountHolder;
    double balance;
};

int main() { 
    BankAccount b1(100); 
    BankAccount b2(200); 
    if (b1.compare(b2)) { 
        cout << "B1 has more balance!\n";
    } else { 
        cout << "B2 has more balance!\n";
    }
}