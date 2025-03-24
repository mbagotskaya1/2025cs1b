#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void printList(Node* head) { 
    if (head == nullptr) return;
    Node* p = head;
    do {
        cout << p->val << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}


void addToCircularList(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void splitCircularList(Node* head, Node*& firstHalf, Node*& secondHalf) {
    if (head == nullptr) return;
    Node* one = head;
    Node* two = head;
    while (two->next != head && two->next->next != head) {
        one = one->next;
        two = two->next->next;
    }

    firstHalf = head;
    secondHalf = one->next;
    one->next = firstHalf; 

    Node* temp = secondHalf;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = secondHalf;
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 6; ++i) {
        addToCircularList(head, i);
    }

    cout << "original circular list: ";
    printList(head);

    Node* firstHalf = nullptr;
    Node* secondHalf = nullptr;

    splitCircularList(head, firstHalf, secondHalf);

    cout << "first half of the circular list: ";
    printList(firstHalf);

    cout << "second half of the circular list: ";
    printList(secondHalf);

    return 0;
}