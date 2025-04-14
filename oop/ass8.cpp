#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Book {
    private:
        int bookID;
        string title;
        string author;
        float price;
    
    public:
        Book() : bookID(0), title(""), author(""), price(0) {}
        Book(int id, string t, string a, float p) : bookID(id), title(t), author(a), price(p) {}
        ~Book() {}
    
        void inputBook() {
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

        void displayBook() const {
            cout << "ID: " << bookID << ", Title: " << title << ", Author: " << author << ", Price: $" << price << endl;
        }

        int getBookID() const { return bookID; }
        string getBookTitle() const { return title; }
        float getPrice() const { return price; }
};

class Borrower {
    private:
        int borrowerID;
        string name;
        string email;
        
    public:
        Borrower() : borrowerID(0), name(""), email("") {}
        Borrower(int id, string n, string e) : borrowerID(id), name(n), email(e) {}
        ~Borrower() {}
        
        void inputBorrower() {
            cout << "Enter Borrower ID: "; 
            cin >> borrowerID;
            cin.ignore();
            cout << "Enter Name: "; 
            getline(cin, name);
            cout << "Enter Email: "; 
            getline(cin, email);
        }

        void displayBorrower() const {
            cout << "ID: " << borrowerID << ", Name: " << name << ", Email: " << email << endl;
        }

        int getBorrowerID() const { return borrowerID; }
        string getBorrowerName() const { return name; }
};

class Transaction {
    private:
        int transactionID;
        const Book& book;
        const Borrower& borrower;
        string date;

    public:
        Transaction(int id, const Book& b, const Borrower& br, string d) : transactionID(id), book(b), borrower(br), date(d) {}
        ~Transaction() {}

        void displayTransaction() const {
            cout << "Transaction ID: " << transactionID << ", Book: " << book.getBookTitle()
                    << ", Borrower: " << borrower.getBorrowerName() << ", Date: " << date << endl;
        }

        int getTransactionID() const { return transactionID; }
        string getTransactionDate() const { return date; }
};

class Library {
    private:
        Book** books;
        Borrower** borrowers;
        Transaction** transactions;
        int bookCount, borrowerCount, transactionCount;
        int bookCapacity, borrowerCapacity, transactionCapacity;
    
    public:
        Library() : bookCount(0), borrowerCount(0), transactionCount(0), bookCapacity(10), borrowerCapacity(10), transactionCapacity(10) {
            books = new Book*[bookCapacity];
            borrowers = new Borrower*[borrowerCapacity];
            transactions = new Transaction*[transactionCapacity];
        }
    
        ~Library() {
            for (int i = 0; i < bookCount; i++) delete books[i];
            for (int i = 0; i < borrowerCount; i++) delete borrowers[i];
            for (int i = 0; i < transactionCount; i++) delete transactions[i];
            delete[] books;
            delete[] borrowers;
            delete[] transactions;
        }
    
        void addBook(Book* book) {
            if (bookCount == bookCapacity) return;
            books[bookCount++] = book;
        }
    
        void addBorrower(Borrower* borrower) {
            if (borrowerCount == borrowerCapacity) return;
            borrowers[borrowerCount++] = borrower;
        }
    
        void recordTransaction(Transaction* transaction) {
            if (transactionCount == transactionCapacity) return;
            transactions[transactionCount++] = transaction;
        }
    
        Book* searchBookByTitle(const string& title) const {
            for (int i = 0; i < bookCount; i++) {
                if (books[i]->getBookTitle() == title)
                    return books[i];
            }
            return nullptr;
        }
    
        Borrower* searchBorrowerByName(const string& name) const {
            for (int i = 0; i < borrowerCount; i++) {
                if (borrowers[i]->getBorrowerName() == name)
                    return borrowers[i];
            }
            return nullptr;
        }
    
        void displayAllBooks() const {
            for (int i = 0; i < bookCount; i++) {
                books[i]->displayBook();
            }
        }
    
        void displayAllBorrowers() const {
            for (int i = 0; i < borrowerCount; i++) {
                borrowers[i]->displayBorrower();
            }
        }
    
        void displayAllTransactions() const {
            for (int i = 0; i < transactionCount; i++) {
                transactions[i]->displayTransaction();
            }
        }
};

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
