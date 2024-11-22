#include <bits/stdc++.h>
using namespace std;

// Define a node structure for the linked list
class node {
public:
    int data;
    node* next;

    // Constructor
    node(int value) {
        data = value;
        next = nullptr;
    }
};
// Function to insert a new node at the beginning of the list
void insertAtHead(node*& head, int value) {
    node* newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

// Function to delete node
void deleteNode(node*& head, int value) {
    if (head == nullptr) {
        return; // List is empty
    }

    // Check if the head node is the one to be deleted
    if (head->data == value) {
        node* temp = head;
        head = head->next; // Move head to the next node
        delete temp;       // Free the memory of the deleted node
        return;
    }

    // Traverse the list to find the node to delete
    node* current = head;
    node* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    // If the node with the value is found
    if (current != nullptr) {
        previous->next = current->next; // Bypass the current node
        delete current;                  // Free the memory of the deleted node
    }
}

void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    node* head = nullptr;

    // Creating initial list
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Initial list:\n";
    display(head);

    // Delete node with value 2
    deleteNode(head, 2);
    cout << "\nList after deleting the node with value 2:\n";
    display(head);

    // Delete node with value 1
    deleteNode(head, 1);
    cout << "\nList after deleting the node with value 1:\n";
    display(head);

    // Try to delete a non-existing value
    deleteNode(head, 5);
    cout << "\nList after trying to delete the node with value 5 (not found):\n";
    display(head);

    return 0;
}
