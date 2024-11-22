#include<bits/stdc++.h>
using namespace std;

// Using for loop
int factorial(int num){
    int fact=1;
    for(int i=1;i<=num;i++){
        fact*=i;
    }
    return fact;
}
// Using Recursion
int factorial(int fact,int num){
    if(num==0 || num==1){
        return fact;
    }
    return factorial(fact*num,num-1);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,fact=1;
    cin>>n;
    cout<<"Using for loop Result: "<<factorial(n)<<"\n";
    cout<<"Using for Recursion Result: "<<factorial(fact,n)<<"\n";
}