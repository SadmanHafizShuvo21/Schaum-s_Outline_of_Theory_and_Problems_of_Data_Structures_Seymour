// Insert an item in kth position 
// You have check it in reverse order
#include<bits/stdc++.h>
using namespace std;

void addItem(int arr[],int n,int position,int item){
    for(int i=n;i>=0;i--){
        if(i==position){
            arr[i]=arr[i-1];
            arr[i-1]=item;
            i--;
            break;
        }
        arr[i]=arr[i-1];
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" \n"[i==n-1];
    }
}

int main(){
    int number,position,item;
    cin>>number>>position>>item;
    int arr[number];
    for(int i=0;i<number;i++){
        cin>>arr[i];
    }
    cout<<"Before insert an element the array is: ";
    display(arr,number);
    addItem(arr,number,position,item);
    cout<<"After insert an element the array is: ";
    display(arr,number+1);
}
/*Input
5 2 8
1 2 3 4 5
Output
Before insert an element the array is: 1 2 3 4 5
After insert an element the array is: 1 8 2 3 4 5
*/