#include<iostream> 
#include "p7.h"
using namespace std; 

int main() {
    Product* product = new Product(12, "great book", 20);
    product->displayProduct();
    delete product;
}