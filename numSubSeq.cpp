#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD=1e9+7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> pow2(n,1);
        for(int i=1;i<n;i++){
            pow2[i]=(pow2[i-1]*2)%MOD;
        }
        int left=0, right=nums.size()-1;
        int result=0;

        while(left<=right){
            if(nums[left]+nums[right]<=target){
                result=(result+pow2[right-left])%MOD;
                left++;
            }else{
                right--;
            }
        }
        return result;
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