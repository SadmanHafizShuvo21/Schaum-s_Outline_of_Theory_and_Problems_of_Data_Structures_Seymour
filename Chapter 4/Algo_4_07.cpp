// // Matrix multriplication
// #include<bits/stdc++.h>
// using namespace std;

// void display(const vector<vector<int>>& arr, int n, int m){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" \n"[j==m-1];
//         }
//     }
//     cout<<'\n';
// }

// int main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     int rowA,colA,rowB,colB;
//     cin>>rowA>>colA>>rowB>>colB;

//     //Check Matrix multiplication is possible or not
//     if (colA != rowB) {
//         cout << "Matrix multiplication not possible!" << endl;
//         return 1;
//     }
//     vector<vector<int>> matrixA(rowA, vector<int>(colA));
//     vector<vector<int>> matrixB(rowB, vector<int>(colB));
//     vector<vector<int>> result(rowA, vector<int>(colB));
//     // Matrix input
//     for(int i=0;i<rowA;i++){
//         for(int j=0;j<colA;j++){
//             cin>>matrixA[i][j];
//         }
//     }
//     for(int i=0;i<rowB;i++){
//         for(int j=0;j<colB;j++){
//             cin>>matrixB[i][j];
//         }
//     }
//     cout<<"MatrixA: \n";
//     display(matrixA,rowA,colA);
//     cout<<"MatrixB: \n";
//     display(matrixB,rowA,colB);

//     //Matrix multriplication
//     for (int i = 0; i < rowA; i++) {
//         for (int j = 0; j < colB; j++) {
//             for (int k = 0; k < colA; k++) {
//                 result[i][j] += matrixA[i][k] * matrixB[k][j];
//             }
//         }
//     }
//     cout<<"Matrix multriplication result: \n";
//     display(result,rowA,colB);
// }
#include<bits/stdc++.h>
using namespace std;
int main(){
    int rowA,colA,rowB,colB;
    //Input col & row for Matrix
    cin>>rowA>>colA>>rowB>>colB; //MatrixA rowA=2,colA=2, MatrixB rowB=2,colB=3
    //Matrix declare
    int matrixA[rowA][colA],matrixB[rowB][colB];

    //Check condition for Matrix multiplication matixA col equal matrixB rowB
    if(colA!=rowB){
        cout<<"Matrix multiplication is impossible"<<"\n";
        return 0;
    }
    // Input MatrixA from user which is two dimension
    for(int i=0;i<rowA;i++){
        for(int j=0;j<colA;j++){
            cin>>matrixA[i][j];
        }
    }
    //Print MatrixA what we input
    cout<<"Matrix A: \n"; 
    for(int i=0;i<rowA;i++){
        for(int j=0;j<colA;j++){
            cout<<matrixA[i][j]<<" ";
        }
        cout<<"\n";
    }
    // Input MatrixB from user which is two dimension
    for(int i=0;i<rowB;i++){
        for(int j=0;j<colB;j++){
            cin>>matrixB[i][j];
        }
    }
    //Print MatrixA what we input
    cout<<"Matrix B: \n"; 
    for(int i=0;i<rowB;i++){
        for(int j=0;j<colB;j++){
            cout<<matrixB[i][j]<<" ";
        }
        cout<<"\n";
    }
    //For multiplication let use result[rowA][colB]
    int result[rowA][colB];

    // Calculate matrix multiplication
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            for (int k = 0; k < colA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];//result[i][j] is the formula for multriplication
            }
        }
    }
    //Print MatrixA & MatrixB result
    cout<<"Matrix A and Matrix B multiplication result: \n"; 
    for(int i=0;i<rowB;i++){
        for(int j=0;j<colB;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}