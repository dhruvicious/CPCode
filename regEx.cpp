#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        function<bool(int, int)> backtrack = [&](int i, int j) -> bool {
            bool result;
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            if (j == m) {
                result = (i == n);
            } else {
                bool firstMatch = (i < n && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < m && p[j + 1] == '*') {
                    result = backtrack(i, j + 2) || (firstMatch && backtrack(i + 1, j));
                } else {
                    result = firstMatch && backtrack(i + 1, j + 1);
                }
            }
            dp[i][j] = result ? 1 : 0;
            return result;
        };
        return backtrack(0, 0);
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}
