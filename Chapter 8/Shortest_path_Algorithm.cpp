#include<bits/stdc++.h>
using namespace std;
long long inf=10e5;
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
                P[i][j]=inf;
            }
            else{
                P[i][j]=A[i][j];
            }
        }
    }
    for(int k=0;k<nodes;k++){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                P[i][j]=min(P[i][j],(P[i][k] + P[k][j]));
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
7 5 0 0 
7 0 0 2
0 3 0 0
4 0 1 0
Output
7 5 8 7
6 6 3 2
9 3 6 5
4 4 1 6
*/