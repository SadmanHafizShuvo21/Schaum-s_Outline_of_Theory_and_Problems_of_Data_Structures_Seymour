#include<bits/stdc++.h>
using namespace std;
int main(){
    int nodes;
    cin>>nodes;
    int A[nodes][nodes],P[nodes][nodes];
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            if(A[i][j]==0){
                P[i][j]=0;
            }
            else{
                P[i][j]=1;
            }
        }
    }
    for(int k=0;k<nodes;k++){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                P[i][j]=P[i][j]||(P[i][k] && P[k][j]);
            }
        }
    }
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<P[i][j]<<" \n"[j==nodes-1];
        }
    }
}
/*
Input
4
1 1 0 1
0 1 1 0
0 0 1 1
0 0 0 1
Output
1 1 1 1
0 1 1 1
0 0 1 1
0 0 0 1
*/