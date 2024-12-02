#include<bits/stdc++.h>
using namespace std;

class node{
    public :
    int data;
    node* left;
    node* right;

    node(int value) : data(value),left(nullptr),right(nullptr){}
};
void postorderTraversing(node* root){
    if(root==nullptr){
        return;
    }
    postorderTraversing(root->left);
    postorderTraversing(root->right);
    cout<<root->data<<" ";
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "Inorder Traversal: ";
    postorderTraversing(root);
    cout << "\n";
}