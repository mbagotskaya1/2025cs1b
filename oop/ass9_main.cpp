#include <iostream>
#include <vector>
#include "ass9.h"
using namespace std;

int main() {
    Student s1("Alice", 20, 3.8), s2("Bob", 22, 3.5);
    Professor p1("Dr. Smith", 45, "Computer Science"), p2("Dr. Johnson", 50, "Mathematics");

    Course c1("CS101", "Intro to CS", 3, 2);
    Course c2("MATH101", "Calculus I", 4, 2);

    enrollStudentInCourse(s1, c1);
    c2 += s1;
    enrollStudentInCourse(s2, c1);
    enrollStudentInCourse(s2, c2);

    //s1.unenrollCourse(&c1);

    p1.assignCourse(&c1);
    p1.assignCourse(&c2);
    p2.assignCourse(&c2);

    s1.displayInfo();
    s2.displayInfo();
    p1.displayInfo();
    p2.displayInfo();

    vector<Person*> people = { &s1, &s2, &p1, &p2};
    for (int i = 0; i < people.size(); ++i) {
        people[i]->displayInfo();
        cout << "------------------------\n";
    }

    c1.displayCourseInfo();
    cout << endl;
    c2.displayCourseInfo();

    return 0;
}