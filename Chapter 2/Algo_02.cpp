/*(Quauadratic Equation) This algorithm inputs the coefficients A. B, C of a quadratic equation
and outputs the wad solutions, if any.*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;  //Input the value of equation
    float D = b*b-4*a*c; //You can use replace b*b with pow(b,2)
    if(D>0){
        float x1,x2;
        x1=(-b+sqrt(D))/2*a;
        x2=(-b-sqrt(D))/2*a;
        cout<<x1<<" "<<x2<<"\n";
    }
    else if(D==0){
        float x = -b/2*a;
        cout<<x<<'\n'; // Here two value is same.
    }
    else{
        cout<<"No real solution exist. "<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}