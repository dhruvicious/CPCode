#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void backtrack(vector<int>& x, vector<vector<int>>& ans, int k, int n,
                   int i) {
        if (k == 0) {
            ans.push_back(x);
            return;
        }
        if (i > n) {
            return;
        }
        for (int j = i; j <= n; j++) {
            x.push_back(j);
            backtrack(x, ans, k - 1, n, j + 1);
            x.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> x;
        vector<vector<int>> ans;
        backtrack(x, ans, k, n, 1);
        return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}