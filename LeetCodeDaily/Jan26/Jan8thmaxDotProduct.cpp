#include <algorithm>
#include <climits>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    Solution() {};
    int maxDotProductBackTrackingMemo(vector<int> nums1, vector<int> nums2) {}
    int maxDotProductBacktracking(vector<int>& nums1, vector<int>& nums2) {
        function<int(int, int, bool)> dfs = [&](int i, int j, bool taken) -> int {
            if (i == nums1.size() || j == nums2.size()) {
                return taken ? 0 : INT_MIN;
            }
            int pair = nums1[i] * nums2[j] + max(0, dfs(i + 1, j + 1, true));
            int skip1 = dfs(i + 1, j, taken);
            int skip2 = dfs(i, j + 1, taken);

            return max({pair, skip1, skip2});
        };
        return dfs(0, 0, false);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, INT_MIN));
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                int v1 = nums1[i - 1] * nums2[j - 1];
                int v2 = nums1[i - 1] * nums2[j - 1] + dp[i - 1][j - 1];
                int v3 = dp[i - 1][j];
                int v4 = dp[i][j - 1];
                dp[i][j] = max({v1, v2, v3, v4});
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int& i : nums1) {
        cin >> i;
    }
    for (int& j : nums2) {
        cin >> j;
    }
    Solution* s = new Solution();
    s->maxDotProduct(nums1, nums2);

    return 0;
}
