#include <bits/stdc++.h>
using namespace std;

class node {
   private:
    node* right;
    node* left;
    int val;

   public:
    node(int val) {
        this->val = val;
        this->right = nullptr;
        this->left = nullptr;
    }
    int getVal() { return val; }
    node* getRight() { return right; }
    node* getLeft() { return left; }

    void setLeft(node* left) { this->left = left; }
    void setRight(node* right) { this->right = right; }
};

node* buildTreeInPre(vector<int>& preOrder, vector<int>& inOrder, int start,
                     int end, int& k);
void printPostOrder(node* root);
void printPreOrder(node* root);
void printInOrder(node* root);
void printLevelOrder(node* root);

node* buildTreeInPre(vector<int>& preOrder, vector<int>& inOrder, int start,
                     int end, int& k) {
    if (start > end) {
        return nullptr;
    }
    node* root = new node(preOrder[k++]);
    int i = -1;
    for (int j = start; j <= end; j++) {
        if (inOrder[j] == root->getVal()) {
            i = j;
            break;
        }
    }
    root->setLeft(buildTreeInPre(preOrder, inOrder, start, i - 1, k));
    root->setRight(buildTreeInPre(preOrder, inOrder, i + 1, end, k));

    return root;
}

void printPostOrder(node* root) {
    if (!root) return;
    printPostOrder(root->getLeft());
    printPostOrder(root->getRight());
    cout << (root->getVal()) << ' ';
}

void printPreOrder(node* root) {
    if (!root) return;
    cout << (root->getVal()) << ' ';
    printPreOrder(root->getLeft());
    printPreOrder(root->getRight());
}

void printInOrder(node* root){
    if(!root) return;
    printInOrder(root->getLeft());
    cout<<root->getVal();
    printInOrder(root->getRight());
}

void printLevelOrder(node* root) {
    if (!root) return;

    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        node* x = q.front();
        q.pop();
        if (x != nullptr) {
            cout << x->getVal() << " ";
            if (x->getLeft()) q.push(x->getLeft());
            if (x->getRight()) q.push(x->getRight());
        } else {
            if (!q.empty()) q.push(nullptr);
        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> inOrder(n);
    vector<int> preOrder(n);

    for (int& i : preOrder) cin >> i;
    for (int& i : inOrder) cin >> i;
    int k = 0;
    node* root = buildTreeInPre(preOrder, inOrder, 0, n - 1, k);
    printLevelOrder(root);
    return 0;
}