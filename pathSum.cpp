#include <cstdio>
#include <functional>
#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *right, *left;
    TreeNode(int val) : val(val), right(nullptr), left(nullptr) {}
};

class Solution {
   public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixCount;
        prefixCount[0] = 1;
        function<int(TreeNode*, long long)> dfs = [&](TreeNode* node, long long currSum) -> int {
            if (!node) return 0;
            currSum += node->val;
            int count = 0;
            
            if (prefixCount.count(currSum - targetSum)) {
                count += prefixCount[currSum - targetSum];
            }
            
            prefixCount[currSum]++;
            count += dfs(node->left, currSum);
            count += dfs(node->right, currSum);
            
            prefixCount[currSum]--;
            return count;
        };
        return dfs(root, 0);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
