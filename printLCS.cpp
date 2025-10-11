#include <bits/stdc++.h>
using namespace std;


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1, s2;
    s1 = "abcde";
    s2 = "bcde";
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int n = s1.size(), m = s2.size();

    string ans = "";
    while (n > 0 && m > 0) {
        if (s1[n - 1] == s2[m - 1]) {
            ans.push_back(s1[n - 1]);
            n--;
            m--;
        } else {
            if (dp[n - 1][m] == dp[n][m]) {
                n--;
            } else {
                m--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}