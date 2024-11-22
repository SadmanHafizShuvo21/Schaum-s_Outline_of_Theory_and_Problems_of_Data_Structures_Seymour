/*Largest Element in Array) Given a noncmpty array DATA with N numerical values, this
 algorithm finds the location [DC and the value MAX of the largest clement of DATA.*/

 #include<bits/stdc++.h>
 using namespace std;

 void solve(){
    int inputNum;
    cin>>inputNum;
    int arrNum[inputNum];
    for(int i=0;i<inputNum;i++){
        cin>>arrNum[i];
    }
    int loc=0,maxNum=arrNum[0];
    for(int i=1;i<inputNum;i++){
        if(arrNum[i]>maxNum){
            maxNum=arrNum[i];
            loc=i;
        }
    }
    cout <<"Location: "<<loc+1<<"\n";
    cout <<"Max Number: "<<maxNum<<"\n";
 }

 int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
 }
/*Input
 5
 1 5 18 2 7
Output
Location: 3
Max Number: 18*/