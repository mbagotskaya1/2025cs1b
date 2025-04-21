#include <iostream>
using namespace std;

class Car {
    private:
    string brand;
    int year;
    public:
    Car(const string& b, int y) {
        this->brand = b;
        this->year = y;
    }
    void display() {
        cout << "brand: " << this->brand << endl;
        cout << "year: " << this->year << endl;
    }
};

class Student {
    private:
    string name;
    int age;
    public:
    void setDetails() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
    }
    void getDetails() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Car car1("jeep", 2015);
    car1.display();

    Student student1;
    student1.setDetails();
    student1.getDetails();
}