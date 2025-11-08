#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void backtrack(int target, int i, vector<int>& x, vector<int>& a) {
    int n = a.size();
    if (target == 0) {
        ans.push_back(x);
        return;
    }
    if (i == n) {
        return;
    }

    for (int j = i; j < n; j++) {
        if (a[j] <= target) {
            x.push_back(a[j]);
            backtrack(target - a[j], j, x, a);
            x.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> x;
    backtrack(target, 0, x, candidates);
    return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}