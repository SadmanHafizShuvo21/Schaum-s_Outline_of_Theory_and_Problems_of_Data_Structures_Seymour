// Traversing A Linear array
// You have to print the array
#include<bits/stdc++.h>
using namespace std;
 void traversing(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" \n"[i==n-1];
    }
 }
 int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int arrayElement;// 5
    cin>>arrayElement;
    int arr[arrayElement];
    for(int i=0;i<arrayElement;i++){
        cin>>arr[i];// 1 2 3 4 5
    }
    traversing(arr,arrayElement);
 }