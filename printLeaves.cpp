#include <bits/stdc++.h>
using namespace std;

class node {
   private:
    int val;
    node *right, *left;

   public:  // constructors
    node(int val) : val(val), right(nullptr), left(nullptr) {}
    node() : val(INT_MIN), right(nullptr), left(nullptr) {}
    // getters
    node* getLeft() { return this->left; }
    node* getRight() { return this->right; }
    int getVal() { return this->val; }
    // setters
    void setRight(node* right) { this->right = right; }
    void setLeft(node* left) { this->left = left; }
    void setVal(int val) { this->val = val; }
};

void convertIP(istream& in, ostream& out) {
    string token;
    while (in >> token) {
        if (token == "true")
            continue;
        else if (token == "false")
            out << "-1 ";
        else
            out << token << " ";
    }
}

node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) {
        return nullptr;
    }
    node* root = new node(val);
    root->setLeft(buildTree());
    root->setRight(buildTree());

    return root;
}

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
            curr->setLeft(leftNode);
            q.push(leftNode);
        }

        if (rightVal != -1) {
            node* rightNode = new node(rightVal);
            curr->setRight(rightNode);
            q.push(rightNode);
        }
    }
    return root;
}

void printLeaves(node* root) {
    if (!root) return;
    if (!root->getLeft() && !root->getRight()) {
        cout << root->getVal() << " ";
    }
    printLeaves(root->getLeft());
    printLeaves(root->getRight());
}

void printTree(node* root) {
    if (root == nullptr) return;

    string leftData =
        (root->getLeft()) ? to_string(root->getLeft()->getVal()) : "END";
    string rightData =
        (root->getRight()) ? to_string(root->getRight()->getVal()) : "END";

    cout << leftData << " => " << root->getVal() << " <= " << rightData << "\n";

    printTree(root->getLeft());
    printTree(root->getRight());
}

node* removeLeaveNodes(node* root) {
    if (!root) return nullptr;
    if (!root->getLeft() && !root->getRight()) {
        delete root;
        return nullptr;
    }
    root->setLeft(removeLeaveNodes(root->getLeft()));
    root->setRight(removeLeaveNodes(root->getRight()));

    return root;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string input;
    getline(cin, input);
    istringstream in(input);
    ostringstream out;
    convertIP(in, out);
    string fltInp = out.str();
    istringstream TreeStream(fltInp);
    cin.rdbuf(TreeStream.rdbuf());

    node* root = buildTree();
    removeLeaveNodes(root);
    printTree(root);
    return 0;
}