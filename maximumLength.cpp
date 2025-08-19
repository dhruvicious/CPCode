#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution{
public:
    int maximumLength(vector<int> &nums, int k){
        int res=0;
        vector<vector<int>> patterns={{0,0},{0,1},{1,0},{1,1}};
        for(auto& pattern: patterns){
            int cnt=0;
            for(int num:nums){
                if(num%k==pattern[cnt%k]){
                    cnt++;
                }
            }
            res=max(res, cnt);
        }
        return res;
    }
};

int32_t main(){
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    return 0;
}