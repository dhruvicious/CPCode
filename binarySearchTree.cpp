#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int data;
    node *right, *left;
    node(int data) {
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};

node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;
    node* root = new node(val);
    root->left = buildTree();
    root->right = buildTree();
}

void printPreOrder(node* root) {
    if (!root) return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(node* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(node* root) {
    if (!root) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

node* insertInBST(node* root, int data) {
    if (root == nullptr) {
        return root = new node(data);
    }
    if (root->data > data) {
        root->left = insertInBST(root->left, data);
    } else {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node* buildBST() {
    int val;
    cin >> val;
    node* root = nullptr;
    while (val != -1) {
        root = insertInBST(root, val);
        cin >> val;
    }
    return root;
}

void printInRange(node* root, int k1, int k2) {
    if (!root) return;

    if (root->data >= k1 && root->data <= k2) {
        cout << root->data << " ";
    }
    printInRange(root->left, k1, k2);
    printInRange(root->right, k1, k2);
}

node* search(node* root, int target) {
    if (!root) return nullptr;
    if (root->data == target) return root;
    if (target < root->data)
        return search(root->left, target);
    else
        return search(root->right, target);
}

bool BSTorNOT(node* root, int min = INT_MIN, int max = INT_MAX) {
    if (!root) return true;
    if (root->data <= min || root->data >= max) return false;
    return BSTorNOT(root->left, min, root->data) &&
           BSTorNOT(root->right, root->data, max);
}

pair<int, bool> isBalanced(node* root) {
    pair<int, bool> p;
    if (!root) {
        p.first = 0;
        p.second = true;
        return p;
    }
    pair<int, bool> left = isBalanced(root->left);
    pair<int, bool> right = isBalanced(root->right);

    p.first = max(left.first, right.first) + 1;
    if (abs(left.first - right.first) && left.second && right.second) {
        p.second = true;
    } else {
        p.second = false;
    }
    return p;
}

class LinkedListNode {
   public:
    node *head, *tail;
};

LinkedListNode BSTtoLL(node* root) {
    // baseCase
    if (!root) return {nullptr, nullptr};
    // recursion
    LinkedListNode left = BSTtoLL(root->left);
    LinkedListNode right = BSTtoLL(root->right);

    if (left.tail) left.tail->right = root;
    root->right = right.head;

    node* head = left.head ? left.head : root;
    node* tail = right.tail ? right.tail : root;

    return {head, tail};
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}