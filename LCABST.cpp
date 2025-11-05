#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node *left, *right;
    node() : val(INT_MIN), left(nullptr), right(nullptr) {}
    node(int val) : val(val), left(nullptr), right(nullptr) {}
};

node* insertInBST(node* root, int val) {
    if (!root) return new node(val);
    if (root->val > val) {
        root->left = insertInBST(root->left, val);
    } else {
        root->right = insertInBST(root->right, val);
    }
    return root;
}

void display(node* root) {
    if (!root) return;
    string s = "";
    s += (root->left ? to_string(root->left->val) : "END");
    s += " => " + to_string(root->val) + " <= ";
    s += (root->right ? to_string(root->right->val) : "END");
    cout << s << "\n";
    display(root->left);
    display(root->right);
}
// node* findLCA(node* root, int n1, int n2) {
//     if (!root) return nullptr;
//     if (root->val > n1 && root->val > n2) {
//         return findLCA(root->left, n1, n2);
//     }
//     if (root->val < n1 && root->val < n2) {
//         return findLCA(root->right, n1, n2);
//     }

//     return root;
// }

void duplicateLeft(node* root) {
    if (!root) return;
    duplicateLeft(root->left);
    duplicateLeft(root->right);

    node* oldLeft = root->left;
    node* dup = new node(root->val);
    root->left = dup;
    dup->left = oldLeft;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* root = nullptr;
    int n;
    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        root = insertInBST(root, val);
    }
    // int n1, n2;
    // cin >> n1 >> n2;
    // node* LCA = findLCA(root, n1, n2);
    // cout << LCA->val << endl;

    duplicateLeft(root);
    display(root);
    return 0;
}