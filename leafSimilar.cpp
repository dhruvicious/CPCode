#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

void getLeaves(TreeNode* root, vector<int>& leaves){
    if(!root) return;
    if(!root->left && !root->right){
        leaves.push_back(root->val);
    }
    getLeaves(root->left, leaves);
    getLeaves(root->right, leaves);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2){
    vector<int> leaves1, leaves2;
    getLeaves(root1, leaves1);
    getLeaves(root2, leaves2);
    return leaves1==leaves2;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    
    return 0;
}