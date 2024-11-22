/*Write algorithm which inserts value so that value follows 
the node with location LOC or inserts value as 
the first node when LOC is NULL*/

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

void insertAtHead(node*& head, int value) {
    node* newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

void insertAfterLoc(node*& head, node* loc, int value) {
    node* newNode = new node(value);

    // If loc is NULL, insert at the head of the list
    if (loc == nullptr) {
        insertAtHead(head, value);
        return;
    }

    // Insert new node after the node at loc
    newNode->next = loc->next;
    loc->next = newNode;
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

    // Example usage
    node* loc = head->next;  // Location to insert after (node with value 2)
    insertAfterLoc(head, loc, 4);
    cout << "\nList after inserting 4 after the node with value 2:\n";
    display(head);

    // Inserting at the head (when loc is NULL)
    insertAfterLoc(head, nullptr, 0);
    cout << "\nList after inserting 0 at the head:\n";
    display(head);

    return 0;
}
