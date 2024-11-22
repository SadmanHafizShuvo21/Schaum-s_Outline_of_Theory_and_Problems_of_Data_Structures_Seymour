//Write a code for insertion of an item into a sorted linked list
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

// Function to insert a new value in a sorted linked list
void sortedInsert(node*& head, int value) {
    node* n = new node(value);

    // If the list is empty or the new value should be at the head
    if (head == nullptr || head->data >= value) {
        n->next = head;
        head = n;
        return;
    }

    // Find the location where the new value should be inserted
    node* temp = head;
    while (temp->next != nullptr && temp->next->data < value) {
        temp = temp->next;
    }

    // Insert the new node after the temp node
    n->next = temp->next;
    temp->next = n;
}

int main() {
    node* head = nullptr;

    // Insert elements into the sorted list
    sortedInsert(head, 5);
    sortedInsert(head, 1);
    sortedInsert(head, 8);
    sortedInsert(head, 3);
    sortedInsert(head, 7);
    
    // Display the list after all insertions
    cout << "Sorted Linked List after insertion: ";
    display(head);

    return 0;
}
