#include <iostream>
using namespace std;

class Book {
    public:
    string title;
    string author;
    int year;
    void display() {
        cout << "title: " << title << endl;
        cout << "author: " << author << endl;
        cout << "year: " << year << endl;
    }

    // Book() {
    //     title = "dead souls";
    //     author = "Nikolai Gogol";
    //     year = 1842;
    // }
};

int main() {
    Book book1;
    book1.display();
}