#include <iostream>
using namespace std;

class Car {
    public:
    string brand;
    int year;
    Car(string b, int y) {
        brand = b;
        year = y;
    }
    void display() {
        cout << "brand: " << brand << endl;
        cout << "year: " << year << endl;
    }
};

int main() {
    Car car1("jeep", 2015);
    car1.display();
}