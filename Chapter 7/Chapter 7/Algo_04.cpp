#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } 
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    BinarySearchTree bst;
    bst.root = bst.insert(bst.root, 1);
    bst.insert(bst.root, 2);
    bst.insert(bst.root, 3);
    bst.insert(bst.root, 4);
    bst.insert(bst.root, 5);
    bst.insert(bst.root, 6);
    bst.insert(bst.root, 7);

    cout << "Preorder Traversal: ";
    bst.preorderTraversal(bst.root);
    cout << "\n";

    return 0;
}
