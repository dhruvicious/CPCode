#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        auto freeSwap = [&](int& it1, int& it2) -> void {
            nums[it1] += nums[it2];
            nums[it2] = nums[it1] - nums[it2];
            nums[it1] = nums[it1] - nums[it2];
        };
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i > 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            freeSwap(i, j);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> nums(n);
        for (int& i : nums) cin >> i;
    }

    return 0;
}
