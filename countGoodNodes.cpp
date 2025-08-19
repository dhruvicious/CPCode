#include <bits/stdc++.h>
using namespace std;

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

int dfs(TreeNode* root, int MaxSoFar){
    if(!root) return 0;
    int count=0;
    if(root->val>=MaxSoFar) count=1;
    MaxSoFar=max(MaxSoFar, root->val);
    count+=dfs(root->left, MaxSoFar);
    count+=dfs(root->right, MaxSoFar);
    return count;
}

int goodNodes(TreeNode* root){
    return dfs(root, root->val);
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}