#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int val;
    node *left, *right;
    node() : val(INT_MIN), left(nullptr), right(nullptr) {}
    node(int val) : val(val), left(nullptr), right(nullptr) {}
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
    if (val == -1) return nullptr;
    node* root = new node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printPaths(node* root, vector<int>& arr, int k, int sum) {
    if (!root) return;
    arr.push_back(root->val);
    sum += root->val;
    if (!root->left && !root->right) {
        if (sum == k) {
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i];
                if (i != arr.size() - 1) cout << " ";
            }
            cout << endl;
        }
        arr.pop_back();
        return;
    }
    printPaths(root->left, arr, k, sum);
    printPaths(root->right, arr, k, sum);
    arr.pop_back();
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
    streambuf* cinbuf = cin.rdbuf();
    cin.rdbuf(treeStream.rdbuf());

    node* root = buildTree();
    vector<int> path = {};
    cin.rdbuf(cinbuf);
    int k;
    cin >> k;
    printPaths(root, path, k, 0);
    return 0;
}