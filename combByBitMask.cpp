#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) == k) {
                vector<int> x;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        x.push_back(i + 1);
                    }
                }
                ans.push_back(x);
            }
        }
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