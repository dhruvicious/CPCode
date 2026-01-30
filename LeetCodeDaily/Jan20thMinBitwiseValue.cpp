#include <iostream>
#include <vector>

class Solution {
   public:
    Solution() {}
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            for (int j = 1; j < nums[i]; j++) {
                if ((j | j + 1) == nums[i]) {
                    nums[i] = j;
                    break;
                }
            }
            if (nums[i] == temp) {
                nums[i] = -1;
            }
        }
        return nums;
    }

    std::vector<int> minBitwiseArrayOptimized(std::vector<int>& nums) {
        for (int& x : nums) {
            int res = -1;
            int d = 1;
            while ((x & d) != 0) {
                res = x - d;
                d <<= 1;
            }
            x=res;
        }
        return nums;
    }
};

int main() {
    int t;
    std::cin >> t;
    Solution* s = new Solution();
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int& i : arr) std::cin >> i;
        s->minBitwiseArray(arr);
    }
    return 0;
}
