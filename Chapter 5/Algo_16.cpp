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

// Insert a node at the beginning of the list
void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);

    // If the list is not empty, set up links for the new head
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    
    // Update head to the new node
    head = newNode;
}

// Insert a node at the end of the list
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);

    // If the list is empty, make the new node the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert a node after a given node in the list
void insertAfterNode(Node* prevNode, int value) {
    // Check if the previous node is null
    if (prevNode == nullptr) {
        cout << "The given previous node cannot be NULL.\n";
        return;
    }

    Node* newNode = new Node(value);

    // Set up links for the new node
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    // Update the next node's prev link if it exists
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }

    // Link the previous node to the new node
    prevNode->next = newNode;
}

// Display the list in forward direction
void displayForward(Node* head) {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Display the list in reverse direction
void displayReverse(Node* head) {
    // Traverse to the last node
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        temp = temp->next;
    }

    // Traverse backwards from the last node
    cout << "Reverse: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    // Insert nodes for testing
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    displayForward(head);
    displayReverse(head);

    // Insert a node at the end
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    displayForward(head);
    displayReverse(head);

    // Insert a node after the second node
    insertAfterNode(head->next, 8);

    displayForward(head);
    displayReverse(head);

    return 0;
}
