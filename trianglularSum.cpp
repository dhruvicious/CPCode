#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        while (nums.size() != 1) {
            vector<int> newNums(nums.size() - 1);
            for (int i = 0; i < nums.size() - 1; i++) {
                newNums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums = newNums;
        }
        return nums[0];
    }

    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> coeff(n, 0);
        coeff[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                coeff[j] = (coeff[j] + coeff[j - 1]) % 10;
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + coeff[i] * coeff[i]) % 10;
        }
        return result;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}