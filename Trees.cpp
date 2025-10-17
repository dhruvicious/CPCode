#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int data;
    node *left, *right;
    node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

node* buildTree();
void printTreePreOrder(node* root);
void printTreeInOrder(node* root);
void printTreePostOrder(node* root);
int heightOfTree(node* root);
int countNodes(node* root);

node* buildTree() {
    int data;
    cin >> data;
    if (data = -1) {
        return nullptr;
    }
    node* root = new node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void printTreePreOrder(node* root) {
    if (!root) return;
    cout << root->data << "  ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

void printTreeInOrder(node* root) {
    if (!root) return;
    printTreeInOrder(root->left);
    cout << root->data << " ";
    printTreeInOrder(root->right);
}

void printTreePostOrder(node* root) {
    if (!root) return;
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    cout << root->data << " ";
}

int heightOfTree(node* root) {
    if(!root) return 0;
    int lheight = heightOfTree(root->left);
    int rheight = heightOfTree(root->right);
    return max(lheight,rheight) +1;
}

int countNodes(node* root){
    if(!root) return 0;
    int lCount = countNodes(root->left);
    int rCount = countNodes(root->right);
    return lCount+rCount+1;
}

int diameterOTree(node* root){
    if(!root) return 0;
    int rootDia = heightOfTree(root->left)+heightOfTree(root->right);
    int leftDia = diameterOTree(root->left);
    int rightDia = diameterOTree(root->right);

    return max({rootDia, leftDia, rightDia});
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}