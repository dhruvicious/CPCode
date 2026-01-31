#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxSum = INT_MIN;
        for (int i = 0; i < n / 2; i++) {
            int currSum = nums[i] + nums[n - 1 - i];
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};

int main() {
}
