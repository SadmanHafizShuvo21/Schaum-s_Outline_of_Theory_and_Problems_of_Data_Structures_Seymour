// Delete Pattern P from Text P
#include<bits/stdc++.h>
using namespace std;

void deleteText(string &T, string &P){ //& is used for avoid copy
    int patternSize=P.size();
    int index=T.find(P);
    while (index != -1) {
        T.erase(index, patternSize);
        index = T.find(P);// update index
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string Text,Pattern;
    // Text="This is a test string. Test the test string.";
    // Pattern="text";
    std::getline(std::cin, Text);//getline use to input a text with space
    cin>>Pattern;
    cout<<"Before Deletion the Text is: "<<Text<<"\n";
    deleteText(Text,Pattern);
    cout<<"After Deletion the Text is: "<<Text<<"\n";
}