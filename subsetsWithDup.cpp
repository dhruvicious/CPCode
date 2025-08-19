#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> uniqueSubsets;
        for(int mask =0;mask<(1<<n);mask++){
            vector<int> subset;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    subset.push_back(nums[i]);
                }
            }
            uniqueSubsets.insert(subset);
        }
        vector<vector<int>> retVec(uniqueSubsets.begin(), uniqueSubsets.end());
        return retVec;
    }

    void generateUniqueSubsets(vector<int>& nums, int index, vector<int> curr, set<vector<int>>& result){
        if(index==nums.size()){
            result.insert(curr);
            return;
        }

        generateUniqueSubsets(nums, index+1, curr, result);

        curr.push_back(nums[index]);
        generateUniqueSubsets(nums, index+1, curr, result);
    }

    vector<vector<int>> subsetsWithDupREC(vector<int>& nums){
        sort(nums.begin(), nums.end());
        set<vector<int>> uniqueResults;
        generateUniqueSubsets(nums, 0, {}, uniqueResults);

        return vector<vector<int>>(uniqueResults.begin(), uniqueResults.end());
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