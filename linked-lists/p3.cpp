#include<iostream> 
#include<fstream> 
using namespace std; 

struct Node { 
    int val; 
    Node* next; 
};

void addToTheEnd(Node*& p, int val) {
    Node* newNode = new Node {val, nullptr}; 
    if (p == nullptr) { 
        p = newNode; 
        return; 
    }
    Node* temp = p; 
    while(temp->next != nullptr) { 
        temp = temp->next;
    }
    temp->next = newNode; 
}

Node* readListFromFile(string fn = "p0.txt") { 
    ifstream f(fn); 
    Node* h = nullptr; 
    while(!f.eof()) { 
        int x; 
        f >> x;
        addToTheEnd(h, x);
    }
    f.close();
    return h; 
}

void printList(Node* head) { 
    while(head != nullptr) { 
        cout << head->val << " "; 
        head = head->next;
    }
    cout << endl; 
}

void checkIfCircular(Node* h) {
    Node* p = h->next;
    while(p != h and p!= nullptr) {
        p = p->next;
    }
    if(p == nullptr) {
        cout << "list is not circular!\n";
    } else {
        cout << "list is circular!\n";
    }
}

void makeItCircular(Node* h) {
    Node* p = h;
    while(p->next != nullptr) { // go until we get to the last node
        p = p->next;
    }
    p->next = h;
}

int main() { 
    Node* head = nullptr; 
    head = readListFromFile(); // creating a singly linked list (non-circular)
    printList(head);
    checkIfCircular(head);
    makeItCircular(head);
    cout << "checking again after making the list circular" << endl;
    checkIfCircular(head);
}