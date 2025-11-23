#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node *right, *left;
    node(int val) : val(val), right(nullptr), left(nullptr) {}
    node() : val(INT_MIN), right(nullptr), left(nullptr) {}
};

node* buildFromLevelOrder() {
    int val;
    if (!(cin >> val) || val == -1) return nullptr;
    node* root = new node(val);
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        if (!(cin >> leftVal >> rightVal)) {
            break;
        }

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

void verticalDFS(node* root, int hd, map<int, vector<int>>& mp) {
    if (!root) return;
    mp[hd].push_back(root->val);
    verticalDFS(root->left, hd - 1, mp);
    verticalDFS(root->right, hd + 1, mp);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    node* root = buildFromLevelOrder();

    map<int, vector<int>> mp;
    verticalDFS(root, 0, mp);

    for (auto& p : mp) {
        for (int x : p.second) cout << x << " ";
        cout << endl;
    }
    return 0;
}