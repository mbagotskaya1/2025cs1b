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

void checkForALoop(Node* h) {
    bool cycle = false;
    if(h->next == h) { cycle = true; }
    Node* p = h->next;
    while(p->next != nullptr) {
        Node* q = h;
        while(p->next != q && p != q) {
            q = q->next;
        }
        if(p->next == q) {
            cycle = true;
            break;
        }
        p = p->next;
    }
    if(cycle) {
        cout << "found cycle at " << p->next->val << endl; 
    } else {
        cout << "no cycle found" << endl; 
    }
}

void addRandomCycle(Node* h) {
    Node* last = h;
    int counter = 0;
    while(last->next != nullptr) {
        last = last->next;
        counter++;
    }
    srand(time(0));
    int x = rand() % counter;
    Node* p = h;
    while(p->next != nullptr && x > 0) {
        p = p->next;
        x--;
    }
    last->next = p;
}

int main() { 
    Node* head = nullptr; 
    head = readListFromFile();
    printList(head);
    checkForALoop(head);
    addRandomCycle(head);
    cout << "checking again after adding a cycle" << endl;
    checkForALoop(head);
}