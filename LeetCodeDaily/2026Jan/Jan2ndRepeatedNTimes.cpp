#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ans;
        for (int i : nums) {
            freq[i]++;
        }
        for (auto [num, f] : freq) {
            if (f == nums.size() / 2) ans = num;
        }
        return ans;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
