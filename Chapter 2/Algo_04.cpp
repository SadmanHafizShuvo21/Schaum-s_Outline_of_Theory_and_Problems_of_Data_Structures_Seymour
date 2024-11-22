/*Linear Search) A linear array DATA with N elements and a specific ITEM of information
 arc given. This algorithm finds the location LOC of ITEM in the array DATA or sets
 LOC=O.*/

 #include<bits/stdc++.h>
 using namespace std;

 void solve(){
    int inputNum,item;
    cin>>inputNum>>item;
    int arrNum[inputNum];
    for(int i=0;i<inputNum;i++){
        cin>>arrNum[i];
    }
    int loc=0;
    bool find=false;
    for(int i=0;i<inputNum;i++){
        if(arrNum[i]==item){
            find=true;
            loc=i;
            break;
        }
    }
    if(find){
        cout <<"The Location of the item is: "<<loc+1<<"\n";
    }
    else{
        cout<<"ITEM is not in the array DATA"<<"\n";
    }
 }

 int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
 }
 /*
 Input
 5 2
 1 5 85 25 65
 Output
 ITEM is not in the array DATA

 Input
 5 25
 1 5 85 25 65
 Output
 The Location of the item is: 4
 */