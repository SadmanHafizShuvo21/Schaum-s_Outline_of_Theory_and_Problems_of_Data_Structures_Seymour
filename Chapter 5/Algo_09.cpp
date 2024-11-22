/*
Write a code to find the location LOC of the first node N 
which contains value and location LOCP of the node preceding N. 
If the value doesn't appear in the list , then the procedure sets LOC=NULL ;
and if value appears in the first node then it sets LOCP = NULL
*/
#include <bits/stdc++.h>
using namespace std;

// Define a node structure for the linked list
class node {
public:
    int data;     
    node* next;   
    // Constructor
    node(int val) {
        data = val;
        next = nullptr;
    }
};
// Function to find the location of the first node containing the value
void findLocation(node* &head, int value, int &LOC, int &LOCP) {
    node* temp = head; 
    LOC = 0;           
    LOCP = NULL;       

    while (temp != nullptr) { 
        LOC++; 
        if (temp->data == value) { 
            if (LOC == 1) { // At first node the value is found
                LOCP = NULL; 
            } 
            else {
                LOCP = LOC - 1; 
            }
            return; 
        }
        temp = temp->next; 
    }
    LOC = NULL; // if value is not found in linked list
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

int main() {
    node* head = nullptr; 

    head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    
    // Function to display the linked list
    cout<<"Display the linked list: ";
    display(head);

    int LOC, LOCP; 
    findLocation(head, 3, LOC, LOCP); 
    cout << "Location of node with value 3: " << LOC << endl; 
    cout << "Location of preceding node: " << LOCP << endl; 

    findLocation(head, 1, LOC, LOCP); 
    cout << "Location of node with value 1: " << LOC << endl; 
    cout << "Location of preceding node: " << LOCP << endl; 

    findLocation(head, 5, LOC, LOCP); 
    cout << "Location of node with value 5: " << LOC << endl; 
    cout << "Location of preceding node: " << LOCP << endl; 

    return 0;
}
