#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int findLHS(vector<int>& nums){
    unordered_map<int, int> freq;
    for(int num:nums) freq[num++];

    int maxLength=0;
    for(auto& [n,f]:freq){
        if(freq.count(n+1)){
            maxLength=max(maxLength, freq[n+1]+f);
        }
    }
    return maxLength;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}