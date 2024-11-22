// Find first occcurance in circular header linked list
#include <bits/stdc++.h>
using namespace std;

// Create class for node
class node {
public:
    int data;
    node* next = nullptr;

    node(int value) { // Constructor for node
        data = value;
        next = nullptr;
    }
};

// Insert node at the tail of the list
void insertAtTail(node*& head, int value) {
    node* n = new node(value);

    if (head == nullptr) { // Check if the list is empty
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
}

// Display the linked list
void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to find the location of the first node containing a given value
node* findFirstOccurrence(node* head, int value) {
    node* temp = head;

    // Traverse the list
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp; // Return the node where the value is first found
        }
        temp = temp->next;
    }
    return nullptr; // Return nullptr if the value is not found
}

int main() {
    node* head = nullptr;

    // Insert nodes for testing
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtTail(head, 9);

    display(head);

    int item = 5;
    node* loc = findFirstOccurrence(head, item);

    if (loc != nullptr) {
        cout << "Item " << item << " found at node with data: " << loc->data << "\n";
    } 
    else {
        cout << "Item " << item << " not found in the list.\n";
    }

    return 0;
}
