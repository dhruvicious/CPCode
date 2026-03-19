#include <climits>
#include <cstdio>
#include <queue>

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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int levelSum = 0, maxSum = INT_MIN;
        int level = 1, ans = 1;
        while (!q.empty()) {
            TreeNode* x = q.front();
            q.pop();
            if (x != nullptr) {
                levelSum += x->val;
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            } else {
                if (levelSum > maxSum) {
                    maxSum = levelSum;
                    ans = level;
                }
                levelSum = 0;
                level++;
            }
            if (!q.empty()) q.push(nullptr);
        }
        return ans;
    }
};
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
