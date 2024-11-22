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

// Function to display the linked list
void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to insert a new value at the end (for testing purposes)
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

// Function to delete a node given its location pointer
void deleteNode(node*& head, node* loc) {
    if (loc == nullptr) {
        cout << "Node not found.\n";
        return;
    }

    // If `loc` is the first node (head)
    if (head == loc) {
        head = head->next; // Move head to the next node
        delete loc;
        return;
    }

    // Find the previous node (LOCP) of the node to be deleted
    node* locp = head;
    while (locp->next != loc && locp->next != nullptr) {
        locp = locp->next;
    }

    // If we found the previous node (LOCP)
    if (locp->next == loc) {
        locp->next = loc->next; // Skip the node at `LOC`
        delete loc;              // Delete the node
    }
}

int main() {
    node* head = nullptr;

    // Insert some elements into the list for testing
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    cout << "Original Linked List: ";
    display(head);

    // Let's delete the node with value 3
    node* loc = head->next->next; // Assuming `loc` is the node with value 3
    deleteNode(head, loc);

    cout << "Linked List after deletion: ";
    display(head);

    return 0;
}
