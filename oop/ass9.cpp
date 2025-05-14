#include "ass9.h"
using namespace std;

// Person
Person::Person(string name, int age) : name(name), age(age) {}
string Person::getName() const { return name; }
int Person::getAge() const { return age; }
void Person::displayInfo() const {
    cout << "Name: " << name << ", Age: " << age << endl;
}
Person::~Person() {}

// Student static member
int Student::totalStudentCount = 0;

// Student
Student::Student(string name, int age, double gpa) : Person(name, age), gpa(gpa) {
    studentID = ++totalStudentCount;
}

int Student::getStudentID() const { return studentID; }

void Student::displayInfo() const {
    Person::displayInfo();
    cout << "Student ID: " << studentID << ", GPA: " << gpa << "\nCourses: ";
    for (int i = 0; i < coursesEnrolled.size(); ++i) {
        cout << coursesEnrolled[i]->getTitle();
        if (i != coursesEnrolled.size() - 1) cout << ", ";
    }
    cout << endl << endl;
}

void Student::enrollCourse(Course* course) {
    for (int i = 0; i < coursesEnrolled.size(); ++i) {
        if (coursesEnrolled[i] == course) return;
    }
    coursesEnrolled.push_back(course);
}

void Student::unenrollCourse(Course* course) {
    for (int i = 0; i < coursesEnrolled.size(); ++i) {
        if (coursesEnrolled[i] == course) {
            coursesEnrolled.erase(coursesEnrolled.begin() + i);
            break;
        }
    }
}

// Course
Course::Course(string courseCode, string title, int credits, int maxCapacity)
    : courseCode(courseCode), title(title), credits(credits), maxCapacity(maxCapacity) {}

string Course::getTitle() const { return title; }
int Course::getCurrentEnrollment() const { return enrolledStudents.size(); }
bool Course::isFull() const { return enrolledStudents.size() >= maxCapacity; }

void Course::displayCourseInfo() const {
    cout << "Course: " << title << " (" << courseCode << ", Credits: " << credits << ")\nEnrolled: ";
    for (int i = 0; i < enrolledStudents.size(); ++i) {
        cout << enrolledStudents[i]->getName();
        if (i != enrolledStudents.size() - 1) cout << ", ";
    }
    cout << endl;
}

void Course::addStudent(Student* student) {
    for (int i = 0; i < enrolledStudents.size(); ++i) {
        if (enrolledStudents[i] == student) return;
    }
    if (!isFull()) enrolledStudents.push_back(student);
}

void Course::removeStudent(Student* student) {
    for (int i = 0; i < enrolledStudents.size(); ++i) {
        if (enrolledStudents[i] == student) {
            enrolledStudents.erase(enrolledStudents.begin() + i);
            break;
        }
    }
}

Course& Course::operator+=(Student& student) {
    if (!isFull()) {
        addStudent(&student);
        student.enrollCourse(this);
    }
    return *this;
}

// Professor
Professor::Professor(string name, int age, string department)
    : Person(name, age), department(department) {}

void Professor::assignCourse(Course* course) {
    for (int i = 0; i < coursesTaught.size(); ++i) {
        if (coursesTaught[i] == course) return;
    }
    coursesTaught.push_back(course);
}

void Professor::unassignCourse(Course* course) {
    for (int i = 0; i < coursesTaught.size(); ++i) {
        if (coursesTaught[i] == course) {
            coursesTaught.erase(coursesTaught.begin() + i);
            break;
        }
    }
}

void Professor::displayInfo() const {
    Person::displayInfo();
    cout << "Department: " << department << "\nCourses Taught: ";
    for (int i = 0; i < coursesTaught.size(); ++i) {
        cout << coursesTaught[i]->getTitle();
        if (i != coursesTaught.size() - 1) cout << ", ";
    }
    cout << endl << endl;
}

// Friend function
bool enrollStudentInCourse(Student& student, Course& course) {
    if (course.isFull()) return false;
    for (int i = 0; i < course.enrolledStudents.size(); ++i) {
        if (course.enrolledStudents[i] == &student)
            return false;
    }
    course.addStudent(&student);
    student.enrollCourse(&course);
    return true;
}