// Find the largest element in an array and output the location and value of it
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int numberInArray;
    cin>>numberInArray;
    int arr[numberInArray];
    for(int i=0;i<numberInArray;i++){
        cin>>arr[i];
    }
    int index=0,maxNum=arr[0];
    for(int i=1;i<numberInArray;i++){
        if(arr[i]>maxNum){
            maxNum=arr[i];
            index=i;
        }
    }
    cout<<"The maximum number in array is: "<<maxNum<<"\n";
    cout<<"The location of maximum number is: "<<index+1<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}