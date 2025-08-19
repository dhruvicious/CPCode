#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left=0, right=0;
        set<int> visited;
        int maxSum=0, currSum=0;
        while(right<nums.size()){
            int rightNum=nums[right];

            while(visited.count(rightNum)){
                currSum-=nums[left];
                visited.erase(nums[left]);
                left++;
            }

            visited.insert(rightNum);
            currSum+=rightNum;
            maxSum=max(maxSum, currSum);
            right++;
        }
        return maxSum;
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