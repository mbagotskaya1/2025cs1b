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
    cout << "\n\n";
    cout << "1 - Print all employees\n";
    cout << "2 - Update an employee (by getting its id)\n";
    cout << "3 - Remove an employee\n";
    cout << "4 - Add a new employee\n";
    cout << "5 - Store employees to a file\n";
    cout << "6 - Load employees from a file\n";
    cout << "7 - Search employee by name\n";
    cout << "8 - Print employee with highest salary\n";
    cout << "Enter your choice: ";
    int x;
    cin >> x;
    cin.ignore();
    return x;
}

int readFromFile(Employee e[], string fn = "employees.txt") { 
    ifstream f(fn);
    int i = 0; 
    string s;
    while(!f.eof()) { 
        getline(f ,s);
        e[i].id = stoi(s); 
        
        getline(f, e[i].name); 
        
        getline(f ,s);
        e[i].salary = stoi(s); 
        
        getline(f , e[i].addr.city);         
        getline(f , e[i].addr.state);
        getline(f, s);
        i++;
    };
    f.close(); 
    return i; 
}

void printEmp(Employee e) {
    cout << e.id << ", " << e.name << ", $" << e.salary << ", " << e.addr.city << ", " << e.addr.state << "\n";
}

void printAllEmployees(Employee e[], int count) {
    for (int i = 0; i < count; i++) {
        printEmp(e[i]);
    }
}

void updateEmployee(Employee e[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (e[i].id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, e[i].name);
            cout << "Enter new salary: ";
            cin >> e[i].salary;
            cin.ignore();
            cout << "Enter new city: ";
            getline(cin, e[i].addr.city);
            cout << "Enter new state: ";
            getline(cin, e[i].addr.state);
            cout << "Employee updated successfully.\n";
            return;
        }
    }
}

void removeEmployee(Employee e[], int &count, int id) {
    for (int i = 0; i < count; i++) {
        if (e[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                e[j] = e[j + 1];
            }
            count--;
            cout << "Employee with ID " << id << " removed.\n";
            return;
        }
    }
}

void addEmployee(Employee e[], int &count) {
    cout << "Enter employee ID: ";
    cin >> e[count].id;
    cout << "Enter employee name: ";
    getline(cin, e[count].name);
    cout << "Enter employee salary: ";
    cin >> e[count].salary;
    cout << "Enter employee city: ";
    getline(cin, e[count].addr.city);
    cout << "Enter employee state: ";
    getline(cin, e[count].addr.state);
    count++;
    cout << "Employee added successfully.\n";
}

void storeToFile(Employee e[], int count, string fn = "employees.txt") {
    ofstream f(fn);
    for (int i = 0; i < count; i++) {
        f << e[i].id << endl;
        f << e[i].name << endl;
        f << e[i].salary << endl;
        f << e[i].addr.city << endl;
        f << e[i].addr.state << endl;
    }
    f.close();
    cout << "Employees saved to file.\n";
}

void searchByName(Employee e[], int count, string name) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (e[i].name == name) {
            printEmp(e[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No employee found with name: " << name << "\n";
    }
}

void printHighestSalary(Employee e[], int count) {
    Employee highest = e[0];
    for (int i = 1; i < count; i++) {
        if (e[i].salary > highest.salary) {
            highest = e[i];
        }
    }
    cout << "Employee with highest salary:\n";
    printEmp(highest);
}

int main() {
    Employee employees[100];
    int empCount = 0;
    while (true) {
        int choice = showMenu();
        switch (choice) {
            case 1:
                printAllEmployees(employees, empCount);
                break;
            case 2: {
                int id;
                cout << "Enter employee ID to update: ";
                cin >> id;
                updateEmployee(employees, empCount, id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter employee ID to remove: ";
                cin >> id;
                removeEmployee(employees, empCount, id);
                break;
            }
            case 4:
                addEmployee(employees, empCount);
                break;
            case 5:
                storeToFile(employees, empCount);
                break;
            case 6:
                empCount = readFromFile(employees);
                break;
            case 7: {
                string name;
                cout << "Enter employee name to search: ";
                getline(cin, name);
                searchByName(employees, empCount, name);
                break;
            }
            case 8:
                printHighestSalary(employees, empCount);
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}