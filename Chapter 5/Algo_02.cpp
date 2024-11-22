#include<bits/stdc++.h>
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

// Searching value in linked list
void search(node* &head, int value){
    node* n = new node(value);
    node* temp = head;

    while(temp->next!=nullptr){
        if(temp->data==value){
            cout<<"The value is found at linked list\n";
            return;
        }
        temp = temp->next;
    }
    cout<<"The value is not found at linked list\n";
}

//Find the position of node in linked list
node* findNode(node* head, int value) {
    node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp;  // Item found; return the pointer to the node
        }
        temp = temp->next;  // Move to the next node
    }
    return nullptr;  // Item not found; return nullptr
}


int main(){
    node* head = nullptr;

    insertAtTail(head,1);
    insertAtTail(head,2);
    display(head);
    // search(head,3);
    // search(head,1);
    int item = 2;
    node* loc = findNode(head, item);
    if (loc != nullptr) {
        cout << "Item " << item << " found at node with data: " << loc->data << "\n";
    } else {
        cout << "Item " << item << " not found in the list.\n";
    }
}
