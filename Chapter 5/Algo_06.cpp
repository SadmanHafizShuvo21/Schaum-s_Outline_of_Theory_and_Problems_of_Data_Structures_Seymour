//Write an algorithm with code  which finds the location LOC of the last node in a sorted list such that INFO[LOC]<value or set LOC=NULL
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to insert at the tail of the list (helper function for testing)
void insertAtTail(node*& head, int value) {
    node* n = new node(value);
    if (head == nullptr) {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
}

// Function to display the linked list
void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to find the last location where node->data is less than the given value
node* findLastLessThan(node* head, int value) {
    node* loc = nullptr;  // Initially set LOC to NULL
    node* ptr = head;

    while (ptr != nullptr && ptr->data < value) {
        loc = ptr;      // Update LOC to current node
        ptr = ptr->next; // Move to the next node
    }

    return loc; // Returns the last node with data < value or NULL if none found
}

int main() {
    node* head = nullptr;

    // Creating a sorted list
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtTail(head, 9);

    cout << "List: ";
    display(head);

    int value = 6;
    node* loc = findLastLessThan(head, value);

    if (loc != nullptr) {
        cout << "The last node with value less than " << value << " is: " << loc->data << "\n";
    } else {
        cout << "No node found with value less than " << value << "\n";
    }

    return 0;
}
