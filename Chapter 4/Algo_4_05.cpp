// Bubble sort Algorithm
#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[],int n, int item){
    for(int i=0;i<n;i++){
        if(arr[i]==item){
            return i+1;
        }
    }
    return -1;
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" \n"[i==n-1];
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int number,item;
    cin>>number>>item;
    int arr[number];
    for(int i=0;i<number;i++){
        cin>>arr[i];
    }
    cout<<"The array is: ";
    display(arr,number);
    int index=linearSearch(arr,number,item);
    if(index!=-1){
        cout<<"Item is found in array at index "<<index;
    }
    else{
        cout<<"Item is not found in array";
    }
}