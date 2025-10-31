#include <bits/stdc++.h>
using namespace std;

class node {
   private:
    int val;
    node* right;
    node* left;

   public:
    // constructors
    node(int val) : val(val), right(nullptr), left(nullptr) {}
    node() : val(INT_MIN), right(nullptr), left(nullptr) {}

    // gettersfa
    node* getRight() { return this->right; }
    node* getLeft() { return this->left; }
    int getVal() { return this->val; }

    // setters
    void setRight(node* right) { this->right = right; }
    void setLeft(node* left) { this->left = left; }
};

void convertIP(istream& in, ostream& out) {
    string token;
    while (in >> token) {
        if (token == "true") {
            continue;
        } else if (token == "false") {
            out << "-1 ";
        } else {
            out << token << " ";
        }
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

void printSiblings(node* root) {
    if (!root) return;
    if (root->getLeft() && !root->getRight()) {
        cout << root->getLeft()->getVal() << " ";
    }

    if (root->getRight() && !root->getLeft()) {
        cout << root->getRight()->getVal() << " ";
    }

    printSiblings(root->getLeft());
    printSiblings(root->getRight());
}
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string input;
    getline(cin, input);

    istringstream in(input);
    ostringstream out;

    convertIP(in, out);
    string fltinp = out.str();
    istringstream TreeStream(fltinp);
    cin.rdbuf(TreeStream.rdbuf());

    node* root = buildTree();

    printSiblings(root);

    return 0;
}