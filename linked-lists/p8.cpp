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

void readListFromFile(Node*& h, Node*& t, string fn = "p0.txt") { 
    ifstream f(fn); 
    while(!f.eof()) { 
        int x; 
        f >> x; 
        addToTheEnd(h, t, x); 
    }
    f.close();
}

void removeAll(int x, Node*& head, Node*& tail) { 
    Node* p = head; 
    while(p != nullptr) { 
        // remove p if value is = x
        if (p->val == x) {
            Node* toDelete = p; 
            if (p->next) {  // if not last node - if (p->next != nullptr)
                p->next->prev = p->prev;  // *((*p).next).prev = (*p).prev
            } else {        // if last node
                tail = p->prev;
            }
            if (p->prev) {  // if not first node
                p->prev->next = p->next; 
            } else {        // if first nodw
                head = p->next; 
            }
            p = p->next; 
            delete toDelete; 
        } else { 
            p = p->next; 
        }
    }
}

void printList(Node* head) { 
    int counter = 0; 
    while(head != nullptr) { 
        cout << head->val << " "; 
        head = head->next;  // head = (*head).next
        if (counter++ == 100) { break; }
    }
    cout << endl; 
}

int main() { 
    Node* head = nullptr;
    Node* tail = nullptr; 
    readListFromFile(head, tail); // creating a doubling linked list (non-circular)
    printList(head);
    removeAll(5, head, tail);
    printList(head);
}