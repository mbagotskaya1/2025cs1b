#ifndef ASS8_H
#define ASS8_H

#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    float price;

public:
    Book();
    Book(int id, string t, string a, float p);
    ~Book();

    void inputBook();
    void displayBook() const;

    int getBookID() const;
    string getBookTitle() const;
    string getBookAuthor() const;
    float getPrice() const;
};

class Borrower {
private:
    int borrowerID;
    string name;
    string email;

public:
    Borrower();
    Borrower(int id, string n, string e);
    ~Borrower();

    void inputBorrower();
    void displayBorrower() const;

    int getBorrowerID() const;
    string getBorrowerName() const;
    string getBorrowerEmail() const;
};

class Transaction {
private:
    int transactionID;
    const Book& book;
    const Borrower& borrower;
    string date;

public:
    Transaction(int id, const Book& b, const Borrower& br, string d);
    ~Transaction();

    void displayTransaction() const;

    int getTransactionID() const;
    string getTransactionDate() const;
    string getTransactionInfo() const;
};

class Library {
private:
    Book** books;
    Borrower** borrowers;
    Transaction** transactions;
    int bookCount, borrowerCount, transactionCount;
    int bookCapacity, borrowerCapacity, transactionCapacity;

public:
    Library();
    ~Library();

    void addBook(Book* book);
    void addBorrower(Borrower* borrower);
    void recordTransaction(Transaction* transaction);

    Book* searchBookByTitle(const string& title) const;
    Borrower* searchBorrowerByName(const string& name) const;

    void displayAllBooks() const;
    void displayAllBorrowers() const;
    void displayAllTransactions() const;
};

// class DataHandler {
// private:
//     string bookFile;
//     string borrowerFile;
//     string transactionFile;

// public:
//     DataHandler();

//     bool saveBooks(Book** books, int count) const;
//     bool loadBooks(Book**& books, int& count);

//     bool saveBorrowers(Borrower** borrowers, int count) const;
//     bool loadBorrowers(Borrower**& borrowers, int& count);

//     bool saveTransactions(Transaction** transactions, int count) const;
//     bool loadTransactions(Transaction**& transactions, int& count, Book** books, int bookCount, Borrower** borrowers, int borrowerCount);
// };

#endif