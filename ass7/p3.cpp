#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
};

void printList(Node* head) { 
    while(head != nullptr) { 
        cout << head->val << " "; 
        head = head->next;
    }
    cout << endl; 
}

void insertAtPosition(Node*& head, int pos, int val) {
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (pos <= 0 || head == nullptr) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    Node* temp = head;
    int currentPos = 0;
    while (temp != nullptr && currentPos < pos - 1) {
        temp = temp->next;
        currentPos++;
    }
    if (temp == nullptr) {
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

int main() {
    Node* head = new Node;
    head->val = 1;
    head->next = nullptr;
    head->prev = nullptr;

    Node* second = new Node;
    second->val = 2;
    second->next = nullptr;
    second->prev = head;
    head->next = second;

    Node* third = new Node;
    third->val = 4;
    third->next = nullptr;
    third->prev = second;
    second->next = third;

    cout << "Original list: ";
    printList(head);

    insertAtPosition(head, 2, 3);
    cout << "list after inserting 3 at position 3: ";
    printList(head);

    return 0;
}
