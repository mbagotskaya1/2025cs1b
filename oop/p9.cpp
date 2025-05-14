#include<iostream> 
using namespace std; 

class Passenger {
    private:
    int passengerID;
    string name;
    string contactEmail;
    public:
    Passenger(int id, const string& name, const string& email) : passengerID(id), name(name), contactEmail(email) {}
    ~Passenger() {}
    void displayPassenger() const {
        cout << "ID: " << passengerID << " name: " << name << " email: " << contactEmail << endl;
    }
    int getPassengerID() const {
        return passengerID;
    }
};

class Airport {
    private:
    string airportCode;
    string cityName;
    public:
    Airport(const string& code, const string& city) : airportCode(code), cityName(city) {}
    ~Airport() {}
    void displayAirport() const {
        cout << "airport code: " << airportCode << " city name: " << cityName << endl;
    }
};

Passenger* getPassenger() {
    string name;
    string contactEmail;

    cout << "getting passenger info" << endl;
    cout << "enter name ";
    getline(cin, name);
    cout << "enter email ";
    getline(cin, contactEmail);
    cout << endl;

    return new Passenger(1, name, contactEmail);
}

Airport* getAirport() {
    string code;
    string name;

    cout << "getting airport info" << endl;
    cout << "enter code ";
    cin >> code;
    cout << "enter name ";
    getline(cin, name);
    cout << endl;

    return new Airport(code, name);
}

int main() {
    Passenger* passenger = getPassenger();
    passenger->displayPassenger();

    Airport* airport = getAirport();
    airport->displayAirport();
}