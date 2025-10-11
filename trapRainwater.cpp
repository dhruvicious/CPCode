#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        rightMax[n-1]=height[n-1];
    
        for(int i =1;i<n;i++){
            leftMax[i]=max(leftMax[i-1], height[i]);
        }

        for(int j=n-2;j>=0;j--){
            rightMax[j]=max(rightMax[j+1],height[j]);
        }
        int harvested=0;
        for(int i =0;i<n;i++){
            harvested+=max(0,min(leftMax[i], rightMax[i]))-height[i];
        }
    
        return harvested;
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