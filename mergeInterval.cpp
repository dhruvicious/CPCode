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
    vector<vector<int>> merge(vector<vector<int>> &intervals){
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){ 
            return a[0] < b[0]; 
        });
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i =1;i<intervals.size();i++){
            if(intervals[i][0]<=merged.back()[1]){
                merged.back()[1]=max(merged.back()[1], intervals[i][1]);  
            }else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
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