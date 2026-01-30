#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int ans = 0;
        int n = nums.size();

        for (int b = 29; b >= 0; b--) {
            int target = ans | (1 << b);
            vector<long long> c;
            c.reserve(n);

            for (int x : nums) {
                long long cost = target - (x & target);
                c.push_back(cost);
            }
            nth_element(c.begin(), c.begin() + m, c.end());

            long long cTotal = 0;
            for (int i = 0; i < m; i++) {
                cTotal += c[i];
            }
            if (cTotal <= k) {
                ans = target;
            }
        }
        return ans;
    }
};

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}
