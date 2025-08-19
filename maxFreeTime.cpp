#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int countPossibleOriginalStrings(string word, int k) {
    vector<int> counts;
    int n = word.size();
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && word[j] == word[i]) ++j;
        counts.push_back(j - i);
        i = j;
    }
    int total = accumulate(counts.begin(), counts.end(), 0);
    int m = counts.size();
    vector<int> dp(total + 1, 0);
    dp[0] = 1;
    for (int cnt : counts) {
        vector<int> ndp(total + 1, 0);
        vector<int> prefix(total + 2, 0);
        for (int i = 0; i <= total; ++i)
            prefix[i + 1] = (prefix[i] + dp[i]) % MOD;
        for (int i = 0; i <= total; ++i) {
            if (i >= 1 && i <= cnt + total) {
                int L = max(0, i - cnt);
                int R = i - 1;
                ndp[i] = (prefix[R + 1] - prefix[L] + MOD) % MOD;
            }
        }
        dp = move(ndp);
    }
    int res = 0;
    for (int len = k; len <= total; ++len)
        res = (res + dp[len]) % MOD;
    return res;
}