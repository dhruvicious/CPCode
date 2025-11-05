#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node *right, *left;
    node(int val) : val(val), right(nullptr), left(nullptr) {}
    node() : val(INT_MIN), right(nullptr), left(nullptr) {}
};
node* buildTree();
void printPreOrder(node* root);
void printInOrder(node* root);
void printPostOrder(node* root);

node* insertInBST(node* root, int val) {
    if (!root) return new node(val);
    if (root->val > val)
        root->left = insertInBST(root->left, val);
    else
        root->right = insertInBST(root->right, val);
    return root;
}

node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) {
        return nullptr;
    }
    node* root = new node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

node* buildTree(vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    node* root = new node(arr[mid]);
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);
    return root;
}

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

void replaceSum(node* root, int& sum) {
    if (!root) return;
    replaceSum(root->right, sum);
    sum += root->val;
    root->val = sum;
    replaceSum(root->left, sum);
}
void replaceSumGreater(node* root, int& sum) {
    if (!root) return;
    replaceSumGreater(root->right, sum);
    int original = root->val;
    root->val = sum;
    sum += original;
    replaceSumGreater(root->left, sum);
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

node* buildTreePostIN(vector<int> post, vector<int> in, int start, int end,
                      int& k) {
    if (start > end) return nullptr;
    node* root = new node(post[k--]);
    int i;
    for (int j = start; j <= end; j++) {
        if (root->val == in[j]) {
            i = j;
            break;
        }
    }
    root->right = buildTreePostIN(post, in, i + 1, end, k);
    root->left = buildTreePostIN(post, in, start, i - 1, k);
    return root;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> post(n);
    for (int& i : post) cin >> i;
    int m;
    cin >> m;
    vector<int> in(n);
    for (int& i : in) cin >> i;
    int k = n - 1;
    node* root = buildTreePostIN(post, in, 0, n - 1, k);
    display(root);
    return 0;
}