#include <cstddef>
#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (nums.size() > 1) {
            bool isAsc = true;
            int minSum = numeric_limits<int>::max();
            int targetIdx = -1;

            for (size_t i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (nums[i] > nums[i + 1]) {
                    isAsc = false;
                }
                if (sum < minSum) {
                    minSum = sum;
                    targetIdx = static_cast<int>(i);
                }
            }
            if (isAsc) {
                break;
            }
            count++;
            nums[targetIdx] = minSum;
            nums.erase(nums.begin() + targetIdx + 1);
        }
        return count;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        s.minimumPairRemoval(arr);
    }

    return 0;
}
