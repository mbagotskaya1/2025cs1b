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

Node* createList(int a[5]) { 
    
}

void printList(Node* head) { 
    while(head != nullptr) { 
        cout << head->val << " "; 
        head = head->next;
    }
    cout << endl; 
}

Node* merge(Node* p, Node* q) {
    if (p == nullptr) {
        return q;
    } else if (q == nullptr) {
        return p;
    }
    Node* h;
    Node* t;
    if (q->val < p->val) {
        h = q;
        t = q;
        q = q->next;
    } else {
        h = p;
        t = p;
        p = p->next;
    }
    while (true) {
        if (q->val < p->val) {
            t->next = q;
            q = q->next;
            t = t->next;
            if (q == nullptr) {
                t->next = p;
                break;
            }
        } else {
            t->next = p;
            p = p->next;
            t = t->next;
            if (p = nullptr) {
                t->next = q;
                break;
            }
        }
    }
    return h;
}

int main() { 
    int a[5] {1, 5, 10, 20, 25};
    int b[5] {3, 4, 6, 7, 8};
    Node* list1 = createList(a); 
    Node* list2 = createList(a);
    printList(list1);
    printList(list2);
    merge(list1, list2);
}