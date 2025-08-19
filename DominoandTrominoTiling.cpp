#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int numTiling(int n) {
    const int MOD = 1e9 + 7;

    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<ll> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    ll sum = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + 2 * sum) % MOD;
        sum = (sum + dp[i - 2]) % MOD;
    }
    return dp[n];
}

int main() { return 0; }