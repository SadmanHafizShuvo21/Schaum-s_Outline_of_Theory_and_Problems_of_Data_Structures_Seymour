/*Largest Element in Array) Given a noncmpty array DATA with N numerical values, this
 algorithm finds the location [DC and the value MAX of the largest clement of DATA.*/

 #include<bits/stdc++.h>
 using namespace std;

 void stl(){
    int n;
    std::cin>>n;
    std::vector<int>arr(n);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    auto largest = std::max_element(arr.begin(),arr.end());
    int large = *largest;
    int index = std::distance(arr.begin(), largest);
    std::cout<<"Largest number is "<<large<<" at index "<<index<<"\n";
    
 }

void solveMap() {
    int inputNum;
    cin >> inputNum;
    vector<int> arrNum(inputNum); 
    map<int, int> mp;          

    for (int i = 0; i < inputNum; i++) {
        cin >> arrNum[i];
        if (mp.find(arrNum[i]) == mp.end()) {
            mp[arrNum[i]] = i;
        }
    }
    auto largest = --mp.end();  
    cout << "Largest number is " << largest->first << " at index " << mp[largest->first] << "\n";
}

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
    // solve();
    solveMap();
    // stl();
 }
/*Input
6
1 5 18 2 7 18
Output
Location: 3
Max Number: 18*/