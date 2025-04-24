#include<iostream> 
#include "p7.h"
using namespace std; 

class Inventory {
    private:
    Product** productList;
    int itemCount;
    int capacity;

    public:
    Inventory(int capacity) : itemCount(0), capacity(capacity) {
        productList = new Product*[capacity] {nullptr};
    }
    ~Inventory() {
        for (int i = 0; i < itemCount; i++) {
            if (productList[i]) {
                delete productList[i];
            }
        }
        delete[] productList;
        cout << "destroyed the inventory" << endl;
    }
    bool addProduct(Product* productPtr) {
        if (itemCount < capacity) {
            productList[itemCount++] = productPtr;
            return true;
        }
        else {
            cout << "no more room in inventory" << endl;
            return false;
        }
    }
    void displayInventory() const {
        cout << "displaying inventory: " << endl;
        for (int i = 0; i < itemCount; i++) {
            productList[i]->displayProduct();
        }
    }
};

int main() {
    Product* p1 = new Product(111, "book", 10);
    Product* p2 = new Product(222, "mouse", 20);
    Product* p3 = new Product(333, "door", 30);
    Product* p4 = new Product(444, "window", 40);

    Inventory inventory(3);
    inventory.displayInventory();

    cout << "adding products" << endl;
    inventory.addProduct(p1);
    inventory.addProduct(p2);
    inventory.addProduct(p3);
    inventory.displayInventory(); 

    inventory.addProduct(p4);
    inventory.displayInventory();
}