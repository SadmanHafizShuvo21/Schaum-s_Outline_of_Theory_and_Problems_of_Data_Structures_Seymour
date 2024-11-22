#include<bits/stdc++.h>
using namespace std;
vector<int>v[100001];

int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    
    while(edges--){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x); 

    }
    for(int i=1;i<=nodes;i++){
        cout<<i<<" ";
        for(int j=0;j<v[i].size();j++){
            cout<<"-> "<<v[i][j]<<" \n"[j==v[i].size()-1];
        }
        // cout<<"\n";
    }
}
/*
Input
5 4
1 2
1 3
3 4
3 5 
Output
1 -> 2 -> 3
2 -> 1
3 -> 1 -> 4 -> 5
4 -> 3
5 -> 3 */