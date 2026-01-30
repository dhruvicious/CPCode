#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        function<int(int, int)> rec = [&](int i, int j) -> int {
            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            // Both strings exhausted
            if (i == n && j == m) {
                return dp[i][j] = 0;
            }

            if (i == n) {
                int sum = 0;
                for (int k = j; k < m; k++) {
                    sum += s2[k];
                }
                return dp[i][j] = sum;
            }
            if (j == m) {
                int sum = 0;
                for (int k = i; k < n; k++) {
                    sum += s1[k];
                }
                return dp[i][j] = sum;
            }
            if (s1[i] == s2[j]) {
                return dp[i][j] = rec(i + 1, j + 1);
            }
            int deleteS1 = s1[i] + rec(i + 1, j);
            int deleteS2 = s2[j] + rec(i, j + 1);

            return dp[i][j] = min(deleteS1, deleteS2);
        };
        return rec(0, 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    Solution s;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        s.minimumDeleteSum(s1, s2);
    }
    return 0;
}
