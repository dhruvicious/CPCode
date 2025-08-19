#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int count=0, maxOR=0;

    void dfs(vector<int> nums, int index, int currOR){
        if(index==nums.size()){
            if(currOR==maxOR) count++;
            return;
        }
        dfs(nums, index+1, currOR|nums[index]);
        dfs(nums, index+1, currOR);
    }

    int countMaxOrSubsets(vector<int>& nums){
        for(int num:nums){
            maxOR |= num;
        }
        dfs(nums, 0, 0);
        return count;
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