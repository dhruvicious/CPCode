#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node *left, *right;
    node() : val(INT_MIN), left(nullptr), right(nullptr) {}
    node(int val) : val(val), left(nullptr), right(nullptr) {}
};

node* buildTreeFromLevelOrder() {
    int val;
    if (!(cin >> val) || val == -1) return nullptr;
    node* root = new node(val);
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        if (!(cin >> leftVal >> rightVal)) break;

        if (leftVal != -1) {
            node* leftNode = new node(leftVal);
            curr->left = leftNode;
            q.push(leftNode);
        }
        if (rightVal != -1) {
            node* rightNode = new node(rightVal);
            curr->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLeftView(node* root) {
    if (!root) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            node* curr = q.front();
            q.pop();
            if (i == 0) {
                cout << curr->val << " ";
            }
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

void printRightView(node* root) {
    if (!root) return;
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            node* curr = q.front();
            q.pop();
            if (i == size - 1) {
                cout << curr->val << " ";
            }
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* root = buildTreeFromLevelOrder();
    printRightView(root);
    return 0;
}