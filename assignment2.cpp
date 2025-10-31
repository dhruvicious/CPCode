#include <bits/stdc++.h>
using namespace std;

class node {
   private:
    int val;
    node* left;
    node* right;

   public:
    node(int v) : val(v), left(nullptr), right(nullptr) {}

    node* getLeft() { return left; }
    node* getRight() { return right; }
    int getVal() { return val; }

    void setLeft(node* l) { left = l; }
    void setRight(node* r) { right = r; }
};

node* buildTree() {
    string token;
    if (!(cin >> token)) return nullptr; 

    int val = stoi(token);
    node* root = new node(val);

    string hasLeft;
    cin >> hasLeft;

    if (hasLeft == "true") {
        root->setLeft(buildTree());
    }

    string hasRight;
    cin >> hasRight;

    if (hasRight == "true") {
        root->setRight(buildTree());
    }

    return root;
}


int sumNodes(node* root) {
    if (!root) return 0;
    return root->getVal() + sumNodes(root->getLeft()) + sumNodes(root->getRight());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    node* root = buildTree();
    cout << sumNodes(root);

    return 0;
}