#include<bits/stdc++.h>
using namespace std;
int vis[10001];
vector<int>v[10001];

void DFS(int node){
    vis[node]=1;
    std::cout<<node<<" -> ";
    for(int child : v[node]){
        if(vis[child]==0){
            DFS(child);
        }
    }
}
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    
    while(edges--){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
}
/*
Input
6 5
1 2
2 3
2 4
4 5
4 6
Output
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 
*/