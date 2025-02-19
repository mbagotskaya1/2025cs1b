#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

enum class DayOfWeek {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

void printDay(DayOfWeek day) {
    switch(day) {
        case DayOfWeek::Monday:
            cout << "today is Monday!\n";
            break;
        case DayOfWeek::Tuesday:
            cout << "today is Tuesday!\n";
            break;
        case DayOfWeek::Wednesday:
            cout << "today is Wednesday!\n";
            break;
        case DayOfWeek::Thursday:
            cout << "today is Thursday!\n";
            break;
        case DayOfWeek::Friday:
            cout << "today is Friday!\n";
            break;
        case DayOfWeek::Saturday:
            cout << "today is Saturday!\n";
            break;
        case DayOfWeek::Sunday:
            cout << "today is Sunday!\n";
            break;
        default:
            break;
    }
}

DayOfWeek nextDay(DayOfWeek light) {
    switch(light) {
        case DayOfWeek::Monday:
            return DayOfWeek::Tuesday;
        case DayOfWeek::Tuesday:
            return DayOfWeek::Wednesday;
        case DayOfWeek::Wednesday:
            return DayOfWeek::Thursday;
        case DayOfWeek::Thursday:
            return DayOfWeek::Friday;
        case DayOfWeek::Friday:
            return DayOfWeek::Saturday;
        case DayOfWeek::Saturday:
            return DayOfWeek::Sunday;
        default:
            return DayOfWeek::Monday;
    }
}

int main() {

    cout << "enter a day of the week (1 for Monday, 7 for Sunday): " << endl;
    int dayNum;
    cin >> dayNum;

    DayOfWeek day;
    switch (dayNum) {
        case 1: day = DayOfWeek::Monday; 
            break;
        case 2: day = DayOfWeek::Tuesday; 
            break;
        case 3: day = DayOfWeek::Wednesday; 
            break;
        case 4: day = DayOfWeek::Thursday;
            break;
        case 5: day = DayOfWeek::Friday; 
            break;
        case 6: day = DayOfWeek::Saturday; 
            break;
        case 7: day = DayOfWeek::Sunday; 
            break;
        default:
            return 1;
    }

    while(true) {
        printDay(day);
        this_thread::sleep_for(chrono::seconds(2));
        day = nextDay(day);
    }
}