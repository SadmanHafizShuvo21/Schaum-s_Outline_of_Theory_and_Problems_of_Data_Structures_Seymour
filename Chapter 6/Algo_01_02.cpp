#include<bits/stdc++.h>
using namespace std;
#define MAX 5
int top=-1;
int Stack[MAX];

void push(int item){
    if(top>=MAX-1){
        cout<<"Stack is overflow"<<"\n";
    }
    else{
        Stack[++top]=item;
        cout<<item<<" is push on Stack"<<"\n";
    }
}
void pop(){
    if(top<=0){
        cout<<"Stack is underflow"<<"\n";
    }
    else{
        cout<<Stack[top--]<<" is pop from Stack"<<"\n";
    }
}
void display(){
    if(top<0){
        cout<<"Stack is empty"<<"\n";
    }
    else{
        cout<<"Stack elements are: ";
        for(int i=0;i<=top;i++){
            cout<<Stack[i]<<" \n"[i==top];
        }
    }
}
int main(){
    pop();
    push(1);
    push(2);
    pop();
    display();
}