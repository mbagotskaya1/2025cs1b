#include <iostream>
#include <string>
#include "ass8.h"
using namespace std;


Book::Book() : bookID(0), title(""), author(""), price(0) {}
Book::Book(int id, string t, string a, float p) : bookID(id), title(t), author(a), price(p) {}
Book::~Book() {}
    
void Book::inputBook() {
cout << "Enter Book ID: "; 
cin >> bookID;
cin.ignore();
cout << "Enter Title: "; 
getline(cin, title);
cout << "Enter Author: "; 
getline(cin, author);
cout << "Enter Price: "; 
cin >> price;
}

void Book::displayBook() const {
    cout << "ID: " << bookID << ", Title: " << title << ", Author: " << author << ", Price: $" << price << endl;
}

int Book::getBookID() const { return bookID; }
string Book::getBookTitle() const { return title; }
string Book::getBookAuthor() const { return author; }
float Book::getPrice() const { return price; }


Borrower::Borrower() : borrowerID(0), name(""), email("") {}
Borrower::Borrower(int id, string n, string e) : borrowerID(id), name(n), email(e) {}
Borrower::~Borrower() {}

void Borrower::inputBorrower() {
    cout << "Enter Borrower ID: "; 
    cin >> borrowerID;
    cin.ignore();
    cout << "Enter Name: "; 
    getline(cin, name);
    cout << "Enter Email: "; 
    getline(cin, email);
}

void Borrower::displayBorrower() const {
    cout << "ID: " << borrowerID << ", Name: " << name << ", Email: " << email << endl;
}

int Borrower::getBorrowerID() const { return borrowerID; }
string Borrower::getBorrowerName() const { return name; }
string Borrower::getBorrowerEmail() const { return email; }

Transaction::Transaction(int id, const Book& b, const Borrower& br, string d) : transactionID(id), book(b), borrower(br), date(d) {}
Transaction::~Transaction() {}

void Transaction::displayTransaction() const {
    cout << "Transaction ID: " << transactionID << ", Book: " << book.getBookTitle()
            << ", Borrower: " << borrower.getBorrowerName() << ", Date: " << date << endl;
}

int Transaction::getTransactionID() const { return transactionID; }
string Transaction::getTransactionDate() const { return date; }
string Transaction::getTransactionInfo() const {
    return to_string(transactionID) + "," + to_string(book.getBookID()) + "," + to_string(borrower.getBorrowerID()) + "," + date;
}

Library::Library() : bookCount(0), borrowerCount(0), transactionCount(0), bookCapacity(10), borrowerCapacity(10), transactionCapacity(10) {
            books = new Book*[bookCapacity];
            borrowers = new Borrower*[borrowerCapacity];
            transactions = new Transaction*[transactionCapacity];
        }

Library::~Library() {
    for (int i = 0; i < bookCount; i++) delete books[i];
    for (int i = 0; i < borrowerCount; i++) delete borrowers[i];
    for (int i = 0; i < transactionCount; i++) delete transactions[i];
    delete[] books;
    delete[] borrowers;
    delete[] transactions;
}

void Library::addBook(Book* book) {
    if (bookCount == bookCapacity) return;
    books[bookCount++] = book;
}

void Library::addBorrower(Borrower* borrower) {
    if (borrowerCount == borrowerCapacity) return;
    borrowers[borrowerCount++] = borrower;
}

void Library::recordTransaction(Transaction* transaction) {
    if (transactionCount == transactionCapacity) return;
    transactions[transactionCount++] = transaction;
}

Book* Library::searchBookByTitle(const string& title) const {
    for (int i = 0; i < bookCount; i++) {
        if (books[i]->getBookTitle() == title)
            return books[i];
    }
    return nullptr;
}

Borrower* Library::searchBorrowerByName(const string& name) const {
    for (int i = 0; i < borrowerCount; i++) {
        if (borrowers[i]->getBorrowerName() == name)
            return borrowers[i];
    }
    return nullptr;
}

void Library::displayAllBooks() const {
    for (int i = 0; i < bookCount; i++) {
        books[i]->displayBook();
    }
}

void Library::displayAllBorrowers() const {
    for (int i = 0; i < borrowerCount; i++) {
        borrowers[i]->displayBorrower();
    }
}

void Library::displayAllTransactions() const {
    for (int i = 0; i < transactionCount; i++) {
        transactions[i]->displayTransaction();
    }
}

int main() {
    Library lib;
    int choice;
    do {
        cout << "\n1. Add Book\n2. Add Borrower\n3. Record Transaction\n4. Search Book\n5. Search Borrower\n6. Display Books\n7. Display Borrowers\n8. Display Transactions\n9. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                Book* b = new Book();
                b->inputBook();
                lib.addBook(b);
                break;
            }
            case 2: {
                Borrower* br = new Borrower();
                br->inputBorrower();
                lib.addBorrower(br);
                break;
            }
            case 3: {
                int tid;
                string title, name, date;
                cout << "Transaction ID: "; 
                cin >> tid; 
                cin.ignore();
                cout << "Book Title: "; 
                getline(cin, title);
                cout << "Borrower Name: "; 
                getline(cin, name);
                cout << "Date: "; 
                getline(cin, date);
                Book* b = lib.searchBookByTitle(title);
                Borrower* br = lib.searchBorrowerByName(name);
                if (b && br) {
                    Transaction* tr = new Transaction(tid, *b, *br, date);
                    lib.recordTransaction(tr);
                } else {
                    cout << "Book or Borrower not found.\n";
                }
                break;
            }
            case 4: {
                string title;
                cout << "Book Title: "; 
                getline(cin, title);
                Book* b = lib.searchBookByTitle(title);
                if (b) b->displayBook();
                else cout << "Not found.\n";
                break;
            }
            case 5: {
                string name;
                cout << "Borrower Name: "; 
                getline(cin, name);
                Borrower* br = lib.searchBorrowerByName(name);
                if (br) br->displayBorrower();
                else cout << "Not found.\n";
                break;
            }
            case 6:
                lib.displayAllBooks();
                break;
            case 7:
                lib.displayAllBorrowers();
                break;
            case 8:
                lib.displayAllTransactions();
                break;
        }
    } while (choice != 9);
}
