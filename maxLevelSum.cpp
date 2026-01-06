#include <climits>
#include <iostream>
#include <stdexcept>

using namespace std;

class TreeNode {
   private:
    TreeNode* right;
    TreeNode* left;
    int val;
    bool hasValue;

   public:
    TreeNode(int data) : right(nullptr), left(nullptr), val(data), hasValue(true) {}
    TreeNode() : right(nullptr), left(nullptr), val(INT_MIN), hasValue(false) {}

    void setRight(TreeNode* rTree) {
        if (this->right == nullptr) {
            this->right = rTree;
        } else {
            throw std::logic_error("Right child already assigned");
        }
    }

    TreeNode* getRight() const { return this->right; }

    void setLeft(TreeNode* lTree) {
        if (this->left == nullptr) {
            this->left = lTree;
        } else {
            throw std::logic_error("Left child already assigned");
        }
    }

    TreeNode* getLeft() const { return this->left; }

    void setVal(int data) {
        if (!this->hasValue) {
            this->val = data;
            this->hasValue = true;
        } else {
            throw std::logic_error("Value Already Assigned");
        }
    }
    int getVal() const {
        if (!this->hasValue) {
            throw std::logic_error("Value not initialized");
        }
        return this->val;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}
