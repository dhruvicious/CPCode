#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node *right, *left;
    node(int val) : val(val), right(nullptr), left(nullptr) {}
    node() : val(INT_MIN), right(nullptr), left(nullptr) {}
};

node* insertInBST(node* root, int val) {
    if (root == nullptr) return root = new node(val);
    if (root->val > val) {
        root->left = insertInBST(root->left, val);
    } else {
        root->right = insertInBST(root->right, val);
    }
    return root;
}

node* BuildBST() {
    int val;
    cin >> val;
    node* root = nullptr;
    while (val != -1) {
        root = insertInBST(root, val);
        cin >> val;
    }
    return root;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    node* root = nullptr;
    while(n--){
        int val;
        cin>>val;
        root = insertInBST(root, val);
    }
    printTillK(root, k);
    
    return 0;
}