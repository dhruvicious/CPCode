#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        int n=events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1,0));
        vector<int> endTimes(n);

        for(int i=0;i<n;i++){
            endTimes[i]=events[i][1];
        }
        for(int i=1;i<=n;i++){
            int start=events[i-1][0], value=events[i-1][2];
            int prev=upper_bound(endTimes.begin(), endTimes.begin()+i-1, start-1)-endTimes.begin();
            for(int j=1;j<=k;j++){
                dp[i][j]=max(dp[i-1][j], dp[prev][j-1]+value);
            }
        }
        return dp[n][k];
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