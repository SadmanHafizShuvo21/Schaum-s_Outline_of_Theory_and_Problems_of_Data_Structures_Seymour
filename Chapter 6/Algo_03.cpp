#include<bits/stdc++.h>
using namespace std;

int evaluateRPN(vector<string> &tokens){
    stack<int>st;
    for(string &token : tokens){
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            st.push(stoi(token));
            // std::cout<<token<<" ";
        }
        else{
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if(token=="+"){
                st.push(a+b);
            }
            else if(token=="-"){
                st.push(a-b);
            }
            else if(token=="*"){
                st.push(a*b);
            }
            else if(token=="/"){
                st.push(a/b);
            }
            else if(token=="^"){
                st.push(pow(a,b));
            }
        }
    }
    return st.top();
}
int main(){
    vector<string> tokens={"2", "1", "+", "3", "*","2","^","3","/"};
    cout<<"Result: "<<evaluateRPN(tokens)<<"\n";
}