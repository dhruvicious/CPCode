#include <bits/stdc++.h>
using namespace std;

class node {
   private:
    int val;
    node* right;
    node* left;

   public:
    node(int val) : val(val), right(nullptr), left(nullptr) {}
    node() : val(INT_MIN), right(nullptr), left(nullptr) {}

    node* getRight() { return this->right; }
    node* getLeft() { return this->left; }
    int getVal() { return this->val; }

    void setVal(int val) { this->val = val; }
    void setRight(node* right) { this->right = right; }
    void setLeft(node* left) { this->left = left; }

    ~node() {
        delete this->left;
        delete this->right;
    }
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

void printInOrder(node* root) {
    if (!root) return;
    printInOrder(root->getLeft());
    cout << root->getVal() << " ";
    printInOrder(root->getRight());
}

void printPreOrder(node* root) {
    if (!root) return;
    cout << root->getVal() << " ";
    printPreOrder(root->getLeft());
    printPreOrder(root->getRight());
}

void printPostOrder(node* root) {
    if (!root) return;
    printPostOrder(root->getLeft());
    printPostOrder(root->getRight());
    cout << root->getVal() << " ";
}

vector<vector<int>> LevelOrderList(node* root) {
    if (!root) return {};

    queue<node*> q;
    q.push(root);
    vector<vector<int>> levels;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            node* curr = q.front();
            q.pop();
            level.push_back(curr->getVal());

            if (curr->getLeft()) q.push(curr->getLeft());
            if (curr->getRight()) q.push(curr->getRight());
        }
        levels.push_back(level);
    }

    return levels;
}

void printLevelOrder(node* root) {
    if (!root) return;
    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();
        if (curr == nullptr) {
            cout << '\n';
            if (!q.empty()) q.push(nullptr);
        } else {
            cout << curr->getVal() << " ";
            if (curr->getLeft()) q.push(curr->getLeft());
            if (curr->getRight()) q.push(curr->getRight());
        }
    }
}

void printAlternatingLevelOrder(node* root) {
    if (!root) return;
    queue<node*> q;
    q.push(root);
    int currLevel = 0;
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            node* curr = q.front();
            q.pop();
            level.push_back(curr->getVal());

            if (curr->getLeft()) q.push(curr->getLeft());
            if (curr->getRight()) q.push(curr->getRight());
        }

        if (currLevel % 2 == 1) reverse(level.begin(), level.end());
        for (int val : level) cout << val << " ";
        currLevel++;
    }
}

void oddPrint(vector<vector<int>> ans) {
    cout << '[';
    for (size_t j = 0; j < ans.size(); j++) {
        const vector<int>& v = ans[j];
        cout << '[';
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i != v.size() - 1) cout << ", ";
        }
        cout << ']';
        if (j != ans.size() - 1) cout << ", ";
    }
    cout << ']';
}
    
pair<int, bool> isBalanced(node* root) {
    pair<int, bool> p;
    if (!root) {
        p.first = 0;
        p.second = true;
        return p;
    }

    pair<int, bool> left = isBalanced(root->getLeft());
    pair<int, bool> right = isBalanced(root->getRight());

    p.first = 1 + max(left.first, right.first);
    if (abs(left.first - right.first) <= 1 && left.second && right.second) {
        p.second = true;
    } else {
        p.second = false;
    }

    return p;
}

int sumNodes(node* root) {
    if (!root) return 0;
    int sumLeft = sumNodes(root->getLeft());
    int sumRight = sumNodes(root->getRight());
    int total = sumLeft + sumRight + root->getVal();

    return total;
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
    string fltInp = out.str();

    istringstream treeStream(fltInp);
    cin.rdbuf(treeStream.rdbuf());

    node* root = buildTree();

    cout << sumNodes(root) << endl;

    return 0;
}
