#include <iostream>
using namespace std;

class Person {
    public:
    void display() {
        cout << age << endl;
    }
    private:
    int age;
    string name;
    char gender;

};

int main() {
    Person p;
    p.display();
}