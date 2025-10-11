#include <bits/stdc++.h>
using namespace std;

int topDown(vector<int> &prices, vector<int> &weight, int cap, int n,
            vector<vector<int>> dp) {
    if (n == 0 || cap == 0) {
        return 0;
    }
    if (dp[n][cap] = -1) {
        return dp[n][cap];
    }
    int op1 = INT_MIN, op2 = INT_MIN;
    if (cap >= weight[n - 1]) {
        op1 = prices[n - 1] +
              topDown(prices, weight, cap - weight[n - 1], n - 1, dp);
    }
    op2 = 0 + topDown(prices, weight, cap, n - 1, dp);

    return dp[n][cap] = max(op1, op2);
}

int bottomUp(vector<int> &prices, vector<int> &weight, int Cap, int N) {
    vector<vector<int>> dp(N, vector<int>(Cap, 0));
    for (int n = 1; n <= N; n++) {
        for (int c = 1; c <= Cap; c++) {
            int op1 = INT_MIN, op2 = INT_MIN;
            if (c >= weight[n - 1]) {
                op1 = prices[n - 1] + dp[n - 1][c - weight[n - 1]];
            }
            op2 = dp[n - 1][c];
            dp[n][c] = max(op1, op2);
        }
    }
    return dp[N][Cap];
}

int knapSack(vector<int> prices, vector<int> weight, int cap, int n) {
    if (n == 0 || cap == 0) {
        return 0;
    }
    int op1 = INT_MIN, op2 = INT_MIN;
    if (cap >= weight[n - 1]) {
        op1 = prices[n - 1] +
              knapSack(prices, weight, cap - weight[n - 1], n - 1);
    }
    op2 = 0 + knapSack(prices, weight, cap, n - 1);

    return max(op1, op2);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> prices(n);
    vector<int> weight(n);
    int cap;
    cin >> cap;
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));
    cout << knapSack(prices, weight, cap, n);
    cout << topDown(prices, weight, cap, n, dp);
    cout << bottomUp(prices, weight, cap, n);
    return 0;
}