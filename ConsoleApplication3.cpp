#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

};

Node* head = NULL;

void insertFirst(int value) {
    Node* last;
    Node* newnode = new Node;
    newnode->data = value;
    newnode->next = NULL;
 
    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
    }
    else {
        last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newnode;
        newnode->next = NULL;
    }
}

void insertlast(int value) {
    Node* newnode = new Node;
        newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
		temp->next = newnode;
    }
}

void insertafter(int value, int after) {
    Node* newnode = new Node;
    newnode->data = value;
    newnode->next = NULL;
    Node* temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    if (temp != NULL) {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else {
        cout << "Node with value " << after << " not found." << endl;
    }
}
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

}

int main() {
	insertFirst(10);
	insertFirst(20);
	insertFirst(30);
    insertlast(5);
	insertafter(15, 10);
    display();
    return 0;
}

