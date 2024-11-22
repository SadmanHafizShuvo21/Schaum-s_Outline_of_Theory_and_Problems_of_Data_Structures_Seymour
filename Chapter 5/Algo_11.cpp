// Traversing a circular header list 

#include <bits/stdc++.h>
using namespace std;

// Define a class for the nodes
class Node {
public:
    int data;
    Node* next;

    Node(int value = -1) { // Constructor for header or data node
        data = value;
        next = this;  // Points to itself for the circular nature
    }
};

// Function to insert a node at the tail of the circular list
void insertAtTail(Node* header, int value) {
    Node* newNode = new Node(value);

    // If the list is empty, the header should point to the new node
    if (header->next == header) {
        header->next = newNode;
        newNode->next = header;  // Point back to header to maintain the circular property
        return;
    }

    // Otherwise, traverse to the last node
    Node* temp = header->next;
    while (temp->next != header) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = header;  // Complete the circular link back to header
}

// Function to display the circular linked list starting from the first data node
void display(Node* header) {
    Node* temp = header->next;

    // Check if the list is empty
    if (temp == header) {
        cout << "The list is empty." << endl;
        return;
    }

    cout << "Circular List: ";
    while (temp != header) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "back to start" << endl;
}

int main() {
    // Create a header node
    Node* header = new Node();

    // Insert nodes for testing
    insertAtTail(header, 1);
    insertAtTail(header, 3);
    insertAtTail(header, 5);
    insertAtTail(header, 7);
    insertAtTail(header, 9);

    // Display the list
    display(header);

}
