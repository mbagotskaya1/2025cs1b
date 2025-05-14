#ifndef ASS9_H
#define ASS9_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Course;
class Student;

class Person {
private:
    string name;
    int age;
public:
    Person(string name, int age);
    string getName() const;
    int getAge() const;
    virtual void displayInfo() const;
    virtual ~Person();
};

class Student : public Person {
private:
    static int totalStudentCount;
    int studentID;
    double gpa;
    vector<Course*> coursesEnrolled;
public:
    Student(string name, int age, double gpa);
    int getStudentID() const;
    void enrollCourse(Course* course);
    void unenrollCourse(Course* course);
    void displayInfo() const override;
    friend bool enrollStudentInCourse(Student& student, Course& course);
};

class Course {
private:
    string courseCode;
    string title;
    int credits;
    int maxCapacity;
    vector<Student*> enrolledStudents;
public:
    Course(string courseCode, string title, int credits, int maxCapacity);
    string getTitle() const;
    int getCurrentEnrollment() const;
    bool isFull() const;
    void displayCourseInfo() const;
    void addStudent(Student* student);
    void removeStudent(Student* student);
    Course& operator+=(Student& student);
    friend bool enrollStudentInCourse(Student& student, Course& course);
};

class Professor : public Person {
private:
    string department;
    vector<Course*> coursesTaught;
public:
    Professor(string name, int age, string department);
    void assignCourse(Course* course);
    void unassignCourse(Course* course);
    void displayInfo() const override;
};

bool enrollStudentInCourse(Student& student, Course& course);

#endif
