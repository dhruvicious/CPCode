#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen=1;

        for(int target=0;target<k;target++){
            vector<int> dp(n,1);
            for(int i =1;i<n;i++){
                for(int j =0;j<i;j++){
                    if(nums[i]+nums[j]%k==target){
                        dp[i]=max(dp[i], dp[j]+1);
                    }
                }
                maxLen=max(maxLen, dp[i]);
            }
        }
        return maxLen;
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