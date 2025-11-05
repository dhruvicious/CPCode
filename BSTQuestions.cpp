#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node *left, *right;
    node(int val) : val(val), left(nullptr), right(nullptr) {}
    node() : val(INT_MIN), left(nullptr), right(nullptr) {}
};

struct Info {
    bool isBST;
    int size;
    int minVal;
    int MaxVal;
};

void printInOrder(node* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

void printPreOrder(node* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(node* root) {
    if (!root) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->val << " ";
}

node* buildTree() {
    int val;
    cin >> val;

    if (val == -1) return nullptr;
    node* root = new node(val);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

node* buildTreeFromINPRE(vector<int>& pre, vector<int>& in, int start, int end,
                         int& k) {
    if (start > end) return nullptr;
    node* root = new node(pre[k++]);
    int i;
    for (int j = start; j <= end; j++) {
        if (in[j] == root->val) {
            i = j;
            break;
        }
    }
    root->left = buildTreeFromINPRE(pre, in, start, i - 1, k);
    root->right = buildTreeFromINPRE(pre, in, i + 1, end, k);

    return root;
}

Info isBST(node* root, int& maxSize) {
    {
        if (!root) return {true, 0, INT_MAX, INT_MIN};

        Info left = isBST(root->left, maxSize);
        Info right = isBST(root->right, maxSize);

        Info curr;
        curr.size = left.size + right.size + 1;
        curr.MaxVal = max({root->val, right.MaxVal, left.MaxVal});
        curr.minVal = min({root->val, right.minVal, left.minVal});

        if (left.isBST && right.isBST && root->val > left.MaxVal &&
            root->val < right.minVal) {
            curr.isBST = true;
            maxSize = max(maxSize, curr.size);
        } else {
            curr.isBST = false;
            curr.size = max(left.size, right.size);
        }
        return curr;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> pre(n), in(n);
    for (int& i : pre) cin >> i;
    for (int& i : in) cin >> i;
    int k = 0;
    node* root = buildTreeFromINPRE(pre, in, 0, n - 1, k);
    int maxsize = 0;
    isBST(root, maxsize);
    cout << maxsize << endl;
    return 0;
}