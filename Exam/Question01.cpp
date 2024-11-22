#include<bits/stdc++.h>
#define maxi 10
std::vector<std::vector<int>> matrix(10, std::vector<int>(10,0));
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int node;
    
    std::cin>>node;
    for(int i=0;i<node;i++){
        for(int j=0;j<node;j++){
            std::cin>>matrix[i][j];
        }
    }
    std::cout<<"Input data for Graph: \n";
    for(int i=0;i<node;i++){
        for(int j=0;j<node;j++){
            std::cout<<matrix[i][j]<<" \n"[j==node-1];
        }
    }
    std::cout<<"Add one extra node: \n";
    node+=1;
    matrix[node-1][0]=8,matrix[node-1][1]=4,matrix[node-1][node-1]=2;
    std::cout<<"After adding node and edges on graph:"<<"\n";
    int maxw=INT_MIN,u=INT_MIN,v=INT_MIN;
    for(int i=0;i<node;i++){
        for(int j=0;j<node;j++){
            if(matrix[i][j]>maxw){
                maxw=matrix[i][j];
                u=i,v=j;
            }
            std::cout<<matrix[i][j]<<" \n"[j==node-1];
        }
    }
    std::cout<<"Max weight: "<<matrix[u][v]<<"\n";
    matrix[u][v]=0;
    
    std::cout<<"After deleting max weight the Graph is: \n";
    for(int i=0;i<node;i++){
        for(int j=0;j<node;j++){
            std::cout<<matrix[i][j]<<" \n"[j==node-1];
        }
    }

}