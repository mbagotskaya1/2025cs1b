#ifndef P7_H
#define P7_H
#include<iostream> 
using namespace std; 

class Product {
    private:
    int productID;
    string productName;
    double price;

    public:
    Product(int id, const string& name, double p);
    ~Product() {};
    void displayProduct() const;
    double getPrice() const;
};

#endif