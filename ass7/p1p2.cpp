#include<iostream> 
#include<fstream> 
using namespace std; 

struct Node { 
    int val; 
    Node* next; 
};

Node* removeDuplicates(Node* head) {
    if (!head) return nullptr;
    
    Node* current = head;
    while (current && current->next) {
        if (current->val == current->next->val) {
            Node* temp = current->next;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}

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

Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    Node* temp = head;
    int length = 1;
    while (temp->next) {
        length++;
        temp = temp->next;
    }
    temp->next = head;
    k = k % length;
    int stepsToNewHead = length - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

int main() { 

    Node* head = readListFromFile();
    cout << "original list: " << endl;
    printList(head);

    int k = 2;
    head = rotateRight(head, k);
    cout << "list after rotating right by " << k << " places: " << endl;
    printList(head);


    head = removeDuplicates(head); 
    cout << "list after removing duplicates: " << endl;
    printList(head);
}