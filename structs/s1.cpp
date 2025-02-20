#include <iostream>
#include <fstream>
using namespace std;

struct Address {
    string city;
    string state;
};

struct Employee {
    int id;
    string name;
    int salary;
    Address addr;
};

int showMenu() {
// Print all employees
// Update an employee (by getting its id)
// Remove an employee
// Add a new employee
// Store employees to a file
// Load employees from a file
// Search employee by name
// Print employee with highest salary
cout << "enter your choice: ";
int x;
cin >> x;
return x;
}

void readFromFile(Employee e[], string fn = "employees.txt") {
    ifstream f(fn);
    int i = 0;
    while(!f.eof()) {
        f >> e[i].id;
        f >> e[i].name;
        f >> e[i].salary;
        f >> e[i].addr.city;
        f >> e[i].addr.state;
    }
}

int main() {

    Employee employees[100];
    int employeeCount = 0;

    while(true) {
        int choice = showMenu();
        switch(choice) {
            case 1: printAllEmployees
            case 6: employeeCount = readFromFile(employees); break;
        }
    }
    employees[0].addr.city = "Mission Viejo";
}