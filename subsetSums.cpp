#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   public:
    bool isSubsetSum(vector<int> nums, int target) {
        int n = nums.size();
        int totalSubsets = 1 << n;
        for (int mask = 0; mask < totalSubsets; mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                }
            }
            if (sum == target) return true;
        }
        return false;
    }

    bool helper(vector<int> nums, int target, int index, int currSum) {
        if (index == nums.size()) {
            return currSum == target;
        }
        return helper(nums, target, index + 1, currSum + nums[index]) ||
               helper(nums, target, index + 1, currSum);

        return false;
    }

    bool isSubsetSum(vector<int> nums, int target) {
        return helper(nums, target, 0, 0);
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