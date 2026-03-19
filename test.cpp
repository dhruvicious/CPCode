#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node* right;
    Node* left;
    int   val;
    Node(int val) : right(nullptr), left(nullptr), val(val) {};
    Node(int val, Node* right, Node* left) :
        right(right), left(left), val(val) {};
};

struct LLNode {
    LLNode* next;
    int     val;
    LLNode(int val) : val(val) {};
    LLNode(int val, LLNode* next) : val(val), next(next) {};
};

string solve(vector<string> numArr) {
    sort(numArr.begin(), numArr.end(),
         [](const string& a, const string& b) -> bool {
             return (a + b) > (b + a);
         });
    if (numArr[0] == "0") return "0";
    string res = "";
    for (auto s : numArr) res += s;
    return res;
}

int solveTwo(Node* root) {
    if (root == nullptr) return -1;

    queue<Node*> q;
    q.push(root);
    int rightMostLeaf = root->val;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->left == nullptr && curr->right == nullptr)
            rightMostLeaf = curr->val;

        if (curr->left) q.push(curr->left);

        if (curr->right) q.push(curr->right);
    }
    return rightMostLeaf;
}

double solveThree(LLNode* head, int k) {
    if (head == nullptr) return 0;
    LLNode* start     = head;
    LLNode* end       = head;
    double  windowSum = 0;
    for (int i = 0; i < k && end != nullptr; i++) {
        windowSum += end->val;
        end = end->next;
    }
    double maxAvg = windowSum / k;
    while (end != nullptr) {
        windowSum -= start->val;
        start = start->next;

        windowSum += end->val;
        end = end->next;

        double currAvg = windowSum / k;
        maxAvg         = currAvg > maxAvg ? currAvg : maxAvg;
    }
    return maxAvg;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<string> numArr(n);
        for (string& i : numArr) {
            int x;
            cin >> x;
            i = to_string(x);
        }
        cout << solve(numArr);
    }
}
