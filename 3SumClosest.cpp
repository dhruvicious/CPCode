#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while(left<right){
                int currSum= nums[i]+nums[left]+nums[right];
                if(abs(currSum-target)<abs(closestSum-target)){
                    closestSum=currSum;
                }
                if(currSum<target){
                    left++;
                }else if(currSum>target){
                    right--;
                }else{
                    return target;
                }
            }
        }
        return closestSum;
    }
};

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}