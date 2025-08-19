#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int maxSum(vector<int>& nums){
        int M=INT_MIN;
        int maxSum=0;
        for(int num:nums){
            M=max(M, num);
        }
        if(M<0){
            return M;
        }else{
            set<int> visited;
            for(int num:nums){
                if(num>=0 && !visited.count(num)){
                    maxSum+=num;
                    visited.insert(num);    
                }
            }
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