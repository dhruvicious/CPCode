#include <vector>

using namespace std;

class Solution {
   public:
    bool backtrack(vector<int>& nums, vector<int>& bucket, int index,
                   int target) {
        if (index == nums.size()) return true;
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] + nums[index] > target) continue;
            bucket[i] += nums[index];
            if (backtrack(nums, bucket, index + 1, target)) return true;
            bucket[i] -= nums[index];
            if (bucket[i] == 0) break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % k != 0) return false;

        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        vector<int> bucket(k, 0);
        return backtrack(nums, bucket, 0, target);
    }
};

int main() {
}
