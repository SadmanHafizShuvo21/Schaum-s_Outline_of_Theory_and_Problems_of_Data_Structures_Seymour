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

// Function to find the location of the first occurrence of a given value in a circular list
void findBHL(Node* header, int item, Node*& loc, Node*& locp) {
    loc = nullptr;
    locp = header;
    Node* ptr = header->next;

    // Traverse the list until we either find the item or loop back to the header
    while (ptr != header && ptr->data != item) {
        locp = ptr;
        ptr = ptr->next;
    }

    // Check if the item was found
    if (ptr != header && ptr->data == item) {
        loc = ptr;
    } 
    else {
        loc = nullptr;
    }
}

// Function to delete the first occurrence of a given value in a circular list
void deleteNode(Node* header, int item, Node*& avail) {
    Node* loc = nullptr;
    Node* locp = nullptr;

    // Use findBHL to find the location of the node with the given item and its predecessor
    findBHL(header, item, loc, locp);

    if (loc == nullptr) {
        cout << "Item " << item << " not found in the list." << endl;
        return;
    }

    // If item is found, update pointers to remove the node from the list
    locp->next = loc->next;

    // Add the deleted node to the available list (free list)
    loc->next = avail;
    avail = loc;

    cout << "Item " << item << " deleted from the list." << endl;
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

    display(header);

    Node* avail = nullptr; // Available list for deleted nodes

    int item = 5;
    deleteNode(header, item, avail);

    display(header);

    return 0;
}
