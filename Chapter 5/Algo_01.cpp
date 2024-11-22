#include <bits/stdc++.h>
using namespace std;

// Define a node structure for the linked list
class node {
    public:
    int data;   
    node* next;  

    // Constructor to initialize a new node with a given value
    node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a new node at the beginning of the list
void insertAtHead(node* &head, int val) {
    node* n = new node(val); 
    n->next = head;          
    head = n;                
}

// Function to insert a new node at the end of the list
void insertAtTail(node* &head, int val) {

    node* n = new node(val); 
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
// Insert at the begining of linked list
void insertAtPosition(node* &head, int pos, int val) {
    if (pos == 1) { 
        insertAtHead(head, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    int count = 1;

    // Traverse to the node just before the specified position
    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) { // If position is out of bounds
        cout << "Position out of bounds\n";
        delete n; // Clean up memory if position is invalid
        return;
    }
    // Insert the new node at the specified position
    n->next = temp->next;
    temp->next = n;
}

//Delete at head
void deleteAtHead(node* &head){
    node* toDelete=head;
    head = head->next; // Increase head position by one
    delete toDelete;
}
//Deletion of node
void deletion(node* &head, int val){
    node* temp = head;
    if(head==nullptr){
        return;
    }
    if(head->next==nullptr){
        deleteAtHead(head);
        return;
    }
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* toDelete = temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}

//Reverse the linked list
node* reverseListRecursive(node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    node* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

// Function to search for a key in the list
bool searchItem(node* &head, int key) {
    node* temp = head;      
    while (temp != nullptr) { 
        if (temp->data == key) { 
            return true;
        }
        temp = temp->next;    
    }
    return false;             // Return false if key is not found
}
// Function to display all elements in the list
void display(node* head) {
    node* temp = head;       
    while (temp != nullptr) { 
        cout << temp->data << "->"; 
        temp = temp->next;          
    }
    cout << "NULL\n";         // Indicate the end of the list
}

int main() {
    node* head = nullptr;     // Initialize an empty list

    // Insert elements at the tail of the list
    insertAtTail(head, 1);    // List: 1
    insertAtTail(head, 2);    // List: 1 -> 2
    insertAtTail(head, 3);    // List: 1 -> 2 -> 3

    // Insert an element at the head of the list
    insertAtHead(head, 4);    // List: 4 -> 1 -> 2 -> 3

    // Display the list
    display(head);             // Output: 4 -> 1 -> 2 -> 3 -> NULL

    // Search for an element in the list
    cout << searchItem(head, 5)<<"\n"; // Output: 0 (false) because 5 is not in the list
    
    cout<<"Insert at position 3"<<"\n";
    insertAtPosition(head,3,6);
    // Display the list
    display(head);

    cout<<"Delete at head"<<"\n";
    deleteAtHead(head);
    display(head);
    cout<<"Delete any node in linked list: ";
    deletion(head,3);
    display(head);
    cout<<"Reverse the linked list: ";
    node*newHead = reverseListRecursive(head);
    display(newHead);
}
