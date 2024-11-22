#include <bits/stdc++.h>
using namespace std;
// Create class for node
class node{
    public :
    int data;
    node* next = nullptr;

    node(int value){ // Constructor of node
        data = value;
        next = nullptr;
    }
};

// Insert node at first node
void insertAtHead(node* &head, int val) {
    node* n = new node(val); // Create a new node with the given value
    n->next = head;          // Set the new node's next pointer to the current head
    head = n;                // Update head to point to the new node
}

// Insert node 
void insertAtTail(node* &head, int value){
    node* n = new node(value);

    if(head == nullptr){ // Check node is NULL or not
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!= nullptr){
        temp = temp->next;
    }
    temp->next=n;
}

// Display the linked list
void display(node* &head){
    node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL \n";
}


int main() {
    node* head = nullptr;
    
    // Insert nodes in sorted order for testing
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtTail(head, 9);

    display(head);

    insertAtHead(head,2);
    display(head);
}
