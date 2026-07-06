#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < nums.size(); i++) {
            if (indexMap.count(nums[i])) {
                int prevIndex = indexMap[nums[i]];
                if (abs(i - prevIndex) <= k) {
                    return true;
                }
            }
            indexMap[nums[i]] = i;
        }
        return false;
    }
};
