#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root) return NULL;
    if(root==p || root==q ) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p ,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);
    if(left!=NULL && right!=NULL){
        return root;
    }else if(right==NULL && left!=NULL){
        return left;
    }else{
        return right;
    }
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    


    return 0;
}