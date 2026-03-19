#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
int         INF = 1e9;
vector<int> dp;

int solve(int x, vector<int> coins) {
    if (x == 0) return 0;
    if (x < 0) return INF;

    if (dp[x] != -1) return dp[x];
    int combCount = INF;

    for (size_t i = 0; i < coins.size(); i++) {
        combCount = min(combCount, solve(x - coins[i], coins) + 1);
    }
    return dp[x] = combCount;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int& i : coins) cin >> i;
    dp.resize(x + 1, -1);
    cout << solve(x, coins);
}
