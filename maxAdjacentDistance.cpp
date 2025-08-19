#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int maxAdjacentDistance(vector<int> nums){
    int n=nums.size();
    int maxDiff=INT_MIN;

    for(int i=0;i<n;i++){
        int next=(i+1)%n;
        int diff=abs(nums[i]-nums[next]);
        maxDiff=max(maxDiff, diff);
    }
    return maxDiff;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maxAdjacentDistance(nums)<<" ";


    return 0;
}