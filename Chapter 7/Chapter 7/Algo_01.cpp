#include<bits/stdc++.h>
using namespace std;
class node{
    public :
    int data;
    node* left;
    node* right;

    node(int val) : 
    data(val), left(nullptr), right(nullptr) {}
};

void preorderTraversal(node* root){
    if (root == nullptr){
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
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

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << "\n";
}