#include<iostream> 
#include "p7.h"
using namespace std; 


Product::Product(int id, const string& name, double p) : productID(id), productName(name), price(p > 0 ? p : 0.0) {}
void Product::displayProduct() const {
     cout << "ID: " << productID << " Name: " << productName << " Price: " << price << endl;
}
double Product::getPrice() const {
        return price;
}