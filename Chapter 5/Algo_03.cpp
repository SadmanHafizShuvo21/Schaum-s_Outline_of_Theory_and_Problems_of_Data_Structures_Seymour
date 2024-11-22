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

// Modified search function for a sorted linked list
node* sortedSearch(node* head, int value) {
    node* temp = head;
    
    while (temp != nullptr) {
        if(temp->data > value) {
            return nullptr;  // Early exit since item cannot be in the list
        } 
        else if (value == temp->data) {
            return temp;  // Item found
        }
        temp = temp->next;  // Move to the next node
    }
    return nullptr;  // Item not found in the list
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

    int item = 5;
    node* loc = sortedSearch(head, item);

    if (loc != nullptr) {
        cout << "Item " << item << " found at node with data: " << loc->data << "\n";
    } else {
        cout << "Item " << item << " not found in the list.\n";
    }

    return 0;
}
