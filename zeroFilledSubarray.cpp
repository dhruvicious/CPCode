#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
    public:
        long long zeroFilledSubarray(vector<int>& nums){
            long long result=0;
            long long curr=0;
            for(int num: nums){
                if(num==0){
                    curr++;
                    result+=curr;
                }else{
                    curr=0;
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