#include <bits/stdc++.h>
using namespace std;

class node {
   private:
    node* right;
    node* left;
    int val;

   public:
    node(int val) {
        this->right = nullptr;
        this->left = nullptr;
        this->val = val;
    }
};

node* buildTree(vector<int> inOrder, vector<int> preOrder) {
    
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> preOrder(n);
    vector<int> inOrder(n);

    for (int& i : preOrder) cin >> i;
    for (int& i : inOrder) cin >> i;

    return 0;
}