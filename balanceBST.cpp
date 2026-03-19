#include <algorithm>
#include <iostream>
#include <vector>

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
    void inOrder(TreeNode* node, vector<int> inorderVec) {
        if (node == nullptr) return;
        inOrder(node->left, inorderVec);
        inorderVec.push_back(node->val);
        inOrder(node->right, inorderVec);
    }
    TreeNode* createBST(const vector<int> inorderVec, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;

        TreeNode* left = createBST(inorderVec, start, mid - 1);
        TreeNode* right = createBST(inorderVec, mid + 1, end);

        return new TreeNode(inorderVec[mid], left, right);
    }

   public:
    TreeNode* balanceBST(TreeNode* root) {
        if (root == nullptr) return nullptr;

        vector<int> inorderVec;
        inOrder(root, inorderVec);

        int size = inorderVec.size();

        createBST(inorderVec, 0, size - 1);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
