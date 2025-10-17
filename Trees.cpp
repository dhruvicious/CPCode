#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int data;
    node *left, *right;
    node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

node* buildTree();
void printTreePreOrder(node* root);
void printTreeInOrder(node* root);
void printTreePostOrder(node* root);
int heightOfTree(node* root);
int countNodes(node* root);
int diameterOTree(node* root);
pair<int, int> fastDiameter(node* root);

node* buildTree() {
    int data;
    cin >> data;
    if (data == -1) {
        return nullptr;
    }
    node* root = new node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void printTreePreOrder(node* root) {
    if (!root) return;
    cout << root->data << "  ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

void printTreeInOrder(node* root) {
    if (!root) return;
    printTreeInOrder(root->left);
    cout << root->data << " ";
    printTreeInOrder(root->right);
}

void printTreePostOrder(node* root) {
    if (!root) return;
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    cout << root->data << " ";
}

int heightOfTree(node* root) {
    if (!root) return 0;
    int lheight = heightOfTree(root->left);
    int rheight = heightOfTree(root->right);
    return max(lheight, rheight) + 1;
}

int countNodes(node* root) {
    if (!root) return 0;
    int lCount = countNodes(root->left);
    int rCount = countNodes(root->right);
    return lCount + rCount + 1;
}

int diameterOTree(node* root) {
    if (!root) return 0;
    int rootDia = heightOfTree(root->left) + heightOfTree(root->right);
    int leftDia = diameterOTree(root->left);
    int rightDia = diameterOTree(root->right);

    return max({rootDia, leftDia, rightDia});
}

pair<int, int> fastDiameter(node* root) {  // height,diameter;
    pair<int, int> p;
    if (!root) {
        p.first = p.second = 0;
        return p;
    }
    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);

    int op1 = left.first + right.first;
    int op2 = left.second;
    int op3 = right.second;

    p.second = max({op1, op2, op3});
    p.first = max(left.first, right.first) + 1;
    return p;
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
            cout << x->data << " ";
            q.push(x->left);
            q.push(x->right);
        } else {
            cout << '\n';
            if (!q.empty()) q.push(nullptr);
        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* root = nullptr;
    root = buildTree();
    printLevelOrder(root);
    return 0;
}