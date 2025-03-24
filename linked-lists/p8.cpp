#include<iostream> 
#include<fstream> 
using namespace std; 

struct Node { 
    int val; 
    Node* next; 
    Node* prev;
};

void addToTheEnd(Node*& h, Node*& t, int val) {
    Node* newNode = new Node {val, nullptr, nullptr}; 
    if (h == nullptr) { 
        h = newNode; 
        t = newNode;
        return; 
    }
   t->next = newNode;
   newNode->prev = t;
   t = newNode;
}

void readListFromFile(Node* h, Node* t, string fn = "p0.txt") { 
    ifstream f(fn); 
    while(!f.eof()) { 
        int x; 
        f >> x;
        addToTheEnd(h, t, x);
    }
    f.close();
}

void printList(Node* head) { 
    while(head != nullptr) { 
        cout << head->val << " "; 
        head = head->next;
    }
    cout << endl; 
}

int main() { 
    Node* head = nullptr; 
    Node* tail = nullptr;
    readListFromFile(head, tail);
    printList(head);
}