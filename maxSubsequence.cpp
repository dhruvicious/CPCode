#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed;
        for(int i =0;i<nums.size();i++){
            indexed.push_back({nums[i], i});
        }
        sort(indexed.begin(), indexed.end(), [](auto& a, auto &b){
            return a.first>b.first;
        });
        indexed.resize(k);
        sort(indexed.begin(), indexed.end(), [](auto& a, auto &b){
            return a.second<b.second;
        });

        vector<int> ans;
        for(auto& p:indexed){
            ans.push_back(p.first);
        }
        return ans;
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