// Delete an item in kth position 
// You have check it in order
#include<bits/stdc++.h>
using namespace std;

void deleteItem(int arr[],int n,int position){
    if (position <= 0 || position> n) {
        cout << "Invalid position!" << '\n';
        return;
    }
    for(int i=position-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" \n"[i==n-1];
    }
}

int main(){
    int number,position;
    cin>>number>>position;
    int arr[number];
    for(int i=0;i<number;i++){
        cin>>arr[i];
    }
    cout<<"Before insert an element the array is: ";
    display(arr,number);
    deleteItem(arr,number,position);
    cout<<"After insert an element the array is: ";
    display(arr,number-1);
}
/*Input
5 2 
1 2 3 4 5
Output
Before insert an element the array is: 1 2 3 4 5
After insert an element the array is: 1 3 4 5
*/