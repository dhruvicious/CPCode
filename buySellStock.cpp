#include <algorithm>
#include <climits>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        function<int(int, bool)> backtrack = [&](int day, bool holding) -> int {
            if (day == n) {
                return 0;
            }

            int& ans = dp[day][holding];
            if (ans != INT_MIN) return ans;

            ans = backtrack(day + 1, holding);

            if (!holding) {
                ans = max(ans, -prices[day] + backtrack(day + 1, true));
            } else {
                ans = max(ans, prices[day] - fee + backtrack(day + 1, false));
            }
            return ans;
        };
        return backtrack(0, false);
    }
    int maxProfit2(vector<int>& prices, int fees) {
        int n = prices.size();
        int cash = 0;
        int hold = -prices[0];
        for (int i = 1; i < n; i++) {
            int prevCash = cash;
            cash = max(cash, hold + prices[i] - fees);
            hold = max(hold, prevCash - prices[i]);
        }
        return cash;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
