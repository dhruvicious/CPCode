#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node *right, *left;
    node() : val(INT_MIN), right(nullptr), left(nullptr) {}
    node(int val) : val(val), right(nullptr), left(nullptr) {}
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
            curr->left = new node(leftVal);
            q.push(curr->left);
        }
        if (rightVal != -1) {
            curr->right = new node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

void topViewHelper(node* root, int level, map<int, int>& h) {
    queue<pair<node* /*node of the value*/, int /*level info*/>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        node* x = p.first;
        int currLevel = p.second;

        if (h.count(currLevel) == 0) {
            h[currLevel] = x->val;
        }

        if (x->left) q.push({x->left, currLevel - 1});
        if (x->right) q.push({x->right, currLevel + 1});
    }
}

vector<int> topView(node* root) {
    map<int, int> m;
    topViewHelper(root, 0, m);

    vector<int> ans;
    for (auto& mm : m) {
        ans.push_back(mm.second);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* root = buildTreeFromLevelOrder();
    vector<int> ans = topView(root);
    for (int& i : ans) cout << i << " ";
    return 0;
}