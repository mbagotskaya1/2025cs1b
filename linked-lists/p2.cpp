#include<iostream> 
#include<fstream> 
using namespace std; 

struct Node { 
    int val; 
    Node* next; 
};

void addToTheEnd(Node*& t, int val) {
    Node* newNode = new Node {val, nullptr}; 
    if (t == nullptr) { 
        t = newNode; 
        t->next = t;
        return; 
    }
    newNode->next = t->next;
    t->next = newNode;
    t = newNode; 
}

Node* readListFromFile(string fn = "p0.txt") { 
    ifstream f(fn); 
    Node* t = nullptr; 
    while(!f.eof()) { 
        int x; 
        f >> x;
        addToTheEnd(t, x);
    }
    f.close();
    return t; 
}

void printList(Node* tail) { 
    if(tail == nullptr) { return; }
    Node* p = tail->next;
    while(p != tail) { 
        cout << p->val << " "; 
        p = p->next;
    }
    cout << p->val << " ";
    cout << endl; 
}

int main() { 
    Node* tail = nullptr; 
    tail = readListFromFile();
    printList(tail);
}