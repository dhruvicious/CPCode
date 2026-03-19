#include <algorithm>
#include <cstdio>
#include <functional>
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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        function<pair<int, int>(TreeNode * node)> dfs = [&](TreeNode* node) -> pair<int, int> {
            if (node == nullptr) return {0, 0};

            pair<int, int> leftChild = dfs(node->left);
            pair<int, int> rightChild = dfs(node->right);

            int goLeft = 0;
            int goRight = 0;

            if (node->left != nullptr) {
                goLeft = 1 + leftChild.second;
            }
            if (node->right != nullptr) {
                goRight = 1 + rightChild.first;
            }

            ans = max({ans, goRight, goLeft});
            return {goLeft, goRight};
        };
        dfs(root);
        return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
