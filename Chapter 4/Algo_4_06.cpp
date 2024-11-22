//Binary Search is apply only in sorted array
#include<bits/stdc++.h>
#include<iostream>

#define long long ll;

int binarySearch(int arr[], int x, int n){// Use algorithm 4.6
    int low=0,high=n-1;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;           
        }
    }
    return -1;
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" \n"[i==n-1];
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int number,item;
    std::cin>>number>>item;
    int arr[number];
    for(int i=0;i<number;i++){ //try to input array in sorted way or use sort stl to sort the array
        std::cin>>arr[i];
    }
    
    std::sort(arr,arr+number);

    std::cout<<"After sorting the array: ";
    display(arr,number);
    
    int result=binarySearch(arr,item,number);

    if(result!=0){
        std::cout<<"Item is found in Array at index "<<result+1<<"\n";
    }
    else{
        std::cout<<"Item is not found in Array"<<"\n";
    }
}