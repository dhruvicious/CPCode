#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    // bruteForce
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++) {
            int searchTarget = target - nums[i];
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == searchTarget) {
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }

    // optimized
    vector<int> twoSumOPT(vector<int>& nums, int target) {
        unordered_map<int /*value */, int /*index */> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int searchTarget = target - nums[i];
            if (map.find(searchTarget) != map.end() && map[searchTarget] != i) {
                return {map[searchTarget], i};
            }
        }
        return {};
    }
};
int main() {
    return 0;
}
