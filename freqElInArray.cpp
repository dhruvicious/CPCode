#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

    class Solution {
    public:
        vector<int> ans;
        void rightSideViewHelper(TreeNode* root, int level, map<int, int>& h) {
            if (!root) return;

            if (h.count(level) == 0) {
                h[level] = root->val;
            }

            rightSideViewHelper(root->right, level + 1, h);
            rightSideViewHelper(root->left, level + 1, h);
        }

        vector<int> rightSideView(TreeNode* root) {
            map<int, int> h;
            rightSideViewHelper(root, 1, h);
            for (auto& hp : h) {
                ans.push_back(hp.second);
            }
        }
    };

int main() {}