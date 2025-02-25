#include<iostream> 
#include<fstream> 
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
    for(int i = 0 ; i < count; i++) { 
        printEmp(e[i]);
    }
}

int main() { 
    Employee employees[100];
    int empCount = 0; 
    while(true) { 
        int choice = showMenu(); 
        switch(choice) {
            case 1: printAllEmployees(employees, empCount); break;  
            case 6: empCount = readFromFile(employees); break; 
        }
    }
}