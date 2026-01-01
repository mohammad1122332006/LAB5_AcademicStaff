#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// 1) Insert node at given position
void insertAtPosition(int value, int pos) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

// 2) Delete last node
void deleteLast() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// 3) Display all nodes
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertAtPosition(10, 1);
    insertAtPosition(20, 2);
    insertAtPosition(30, 3);
    insertAtPosition(15, 2);

    display();

    deleteLast();
    display();

    return 0;
}
