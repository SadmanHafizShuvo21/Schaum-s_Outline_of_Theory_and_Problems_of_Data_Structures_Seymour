// Replace pattern P with Q
#include<bits/stdc++.h>
using namespace std;
void replacePattern(string &T, string &P,string &Q){
    int pSize=P.size();
    int qSize=Q.size();
    int index=T.find(P);
    while(index!=-1){
        T.erase(index,pSize);// delete P
        T.insert(index,Q); // insert Q
        index=T.find(P,index+qSize); //update index
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string Text,P,Q;
    // Text="This is a test string. Test the test string.";
    // P="text";
    // Q="sample"
    std::getline(std::cin, Text);//getline use to input a text with space
    cin>>P>>Q;
    cout<<"Before replacement the Text is: "<<Text<<"\n";
    replacePattern(Text,P,Q);
    cout<<"After replacement the Text is: "<<Text<<"\n";
}