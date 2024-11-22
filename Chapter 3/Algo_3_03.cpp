// Pattern Matching Algorithm
#include<bits/stdc++.h>
using namespace std;
void patternMatching(string T, string P){
    int tSize=T.size();
    int pSize=P.size();
    int index=-1;
    bool ok=false; 
    for(int i=0;i<tSize-pSize;i++){
        if(T.substr(i,pSize)==P){ 
            index=i+1;
            ok=true;
            break;
        }
    }
    if(ok){//if Pattern Matching found
       cout<<"Pattern matching is found at index "<<index<<"\n";
    }
    else{
        cout<<"Pattern matching is not found in this Text"<<"\n";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string Text,Pattern;//aaaaaabbbj ab
    cin>>Text>>Pattern;
    patternMatching(Text,Pattern);
}