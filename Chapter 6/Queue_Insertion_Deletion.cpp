#include <iostream>
#define SIZE 5 

using namespace std;

int queue[SIZE]; 
int front = -1;   
int rear = -1;   

// Function to insert an element at the rear of the queue (Enqueue)
void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue is full! Cannot enqueue " << value << "\n";
    } else {
        if (front == -1) front = 0;  
        rear++;
        queue[rear] = value;
        cout << "Inserted " << value << endl;
    }
}

// Function to delete an element from the front of the queue (Dequeue)
void dequeue() {
    if (front == -1) {
        cout << "Queue is empty! Cannot dequeue" << endl;
    } else {
        cout << "Removed " << queue[front] << endl;
        front++;
        // Reset queue when it becomes empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

// Function to display the queue elements
void display() {
    if (front == -1) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  // Queue reaches max size here

    display();

    dequeue();
    dequeue();
    display();

    enqueue(60);  // Attempt to enqueue in a full queue
    dequeue();
    display();

    return 0;
}
