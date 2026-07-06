#include <functional>
#include <iostream>
#include <vector>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
   public:
    int zigZagArrays(int n, int l, int r) {
        int    m = r - l + 1;
        vector dp(n + 1, vector(m + 1, vector<int>(m + 1, -1)));
        function<int(int, int, int)> backtrack = [&](int idx, int prev1,
                                                     int prev2) -> int {
            if (idx == n) {
                return 1;
            }

            int& ans = dp[idx][prev1 + 1][prev2 + 1];
            if (ans != -1) {
                return ans;
            }

            long long res = 0;

            for (int x = 0; x < m; x++) {
                if (prev1 != -1 && x == prev1) {
                    continue;
                }
                if (prev2 != -1) {
                    bool incr = (prev2 < prev1 && prev1 < x);
                    bool decr = (prev2 > prev1 && prev1 > x);
                    if (incr || decr) continue;
                }
                res += backtrack(idx + 1, x, prev1);
                res %= MOD;
            }
            return ans = res;
        };
        return backtrack(0, -1, -1);
    }
};

int main() {
    return 0;
}
