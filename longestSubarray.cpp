#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        vector<int> prefixSum(n,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }        
        int maxLenght=0;
        for(int i =0;i<n;i++){
            if(prefixSum[i]==k){
                maxLenght=max(maxLenght, i+1);
            }
            for(int j=i+1;j<n;j++){
                if(prefixSum[j]-prefixSum[i]==k){
                    maxLenght=max(maxLenght, j-i);
                }
            }
        }
        return maxLenght;
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