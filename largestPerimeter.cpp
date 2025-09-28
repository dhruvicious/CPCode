#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--) {
            if(i-1>=0 &&  i-2>=0){
                if (nums[i - 2] + nums[i - 1] > nums[i]) {
                    return nums[i - 1] + nums[i] + nums[i - 2];
                }
            }
        }
        return 0;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}