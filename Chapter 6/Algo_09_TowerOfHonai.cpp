#include<bits/stdc++.h>
using namespace std;

void Tower(int disks, char Beg, char Aux, char End){
    if(disks==1){
        cout<<Beg<<" to "<<End<<"\n";
        return;
    }
    Tower(disks-1,Beg,End,Aux);
    cout<<Beg<<" to "<<End<<"\n";
    Tower(disks-1,Aux,Beg,End);
}

int main(){
    int n;
    cin>>n;
    cout<<"The number of Disks: "<<n<<"\n";
    Tower(n,'A','B','C');
}
/*
The number of Disks: 3
A to C
A to B
C to B
A to C
B to A
B to C
A to C
*/