#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   private:
    long long totalSum = 0;
    long long maxProductVal = 0;

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subTreeSum = root->val + leftSum + rightSum;

        long long product = subTreeSum * (totalSum - subTreeSum);
        maxProductVal = max(maxProductVal, product);

        return subTreeSum;
    }

   public:
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);
        maxProductVal = 0;
        dfs(root);
        const int MOD = 1e9 + 7;

        return static_cast<int>(maxProductVal % MOD);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
