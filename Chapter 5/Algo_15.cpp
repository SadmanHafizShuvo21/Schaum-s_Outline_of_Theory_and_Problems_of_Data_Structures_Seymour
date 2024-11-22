#include <bits/stdc++.h>
using namespace std;

// Define the class for a node in a doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor for creating a new node
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Insert node at the end of the list
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) { // If the list is empty, set newNode as head
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }

    temp->next = newNode; // Link last node to new node
    newNode->prev = temp;
}

// Display the list in forward direction
void display(Node* head) {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to delete the head node
void deleteHead(Node*& head) {
    if (head == nullptr) return; // Empty list, nothing to delete

    Node* toDelete = head;
    head = head->next; // Move head to the next node

    if (head != nullptr) { // Update the prev pointer of the new head
        head->prev = nullptr;
    }

    delete toDelete; // Free memory of the original head node
}

// Function to delete a node with a specific value
void deleteNode(Node*& head, int value) {
    Node* temp = head;

    // Traverse the list to find the node with the given value
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) { // Value not found in the list
        cout << "Value " << value << " not found in the list.\n";
        return;
    }

    // Node to be deleted is the head node
    if (temp == head) {
        deleteHead(head);
        return;
    }

    // Update the previous node's next pointer
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    // Update the next node's prev pointer
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp; // Free memory of the node to be deleted
}

// Function to delete the last node of the list
void deleteTail(Node*& head) {
    if (head == nullptr) return; // Empty list, nothing to delete

    Node* temp = head;

    // Traverse to the last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // If there is only one node
    if (temp == head) {
        head = nullptr;
    } else {
        temp->prev->next = nullptr; // Disconnect the last node
    }

    delete temp; // Free memory of the last node
}

int main() {
    Node* head = nullptr;

    // Insert nodes for testing
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    display(head);

    // Deleting head node
    deleteHead(head);
    display(head);

    // Deleting a specific node with value 3
    deleteNode(head, 3);
    display(head);

    // Deleting the tail node
    deleteTail(head);
    display(head);

    return 0;
}
