#include <cstdio>
#include <functional>
#include <iostream>
#include <utility>
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
   public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        function<pair<int, TreeNode*>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int, TreeNode*> {
            if (!node) {
                return {0, nullptr};
            }
            auto left = dfs(node->left);
            auto right = dfs(node->right);

            int leftDepth = left.first;
            int rightDepth = right.first;

            if (leftDepth > rightDepth) return {leftDepth + 1, left.second};
            if (rightDepth > leftDepth) return {rightDepth + 1, right.second};

            return {leftDepth + 1, node};
        };
        return dfs(root).second;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}
