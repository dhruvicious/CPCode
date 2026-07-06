#include <vector>

using namespace std;

class Solution {
   public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        for (int& i : nums) {
            i = i == target ? 1 : -1;
        }
        vector<int> prefixSum(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<int> freq(2 * nums.size() + 1, 0);
        int         countGreater   = 0;
        int         totalSubarrays = 0;

        freq[prefixSum[nums.size()] + nums.size()]++;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int curr = prefixSum[i];
            if (nums[i] == 1) {
                countGreater += freq[prefixSum[i + 1] + nums.size()];
            } else {
                countGreater -= freq[curr + nums.size()];
            }

            totalSubarrays += countGreater;
            freq[curr + nums.size()]++;
        }
        return totalSubarrays;
    }
};

int main() {
    return 0;
}
