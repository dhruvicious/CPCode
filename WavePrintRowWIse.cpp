#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

void wavePrint(vector<vector<int>>& arr){
    for(int i =0;i<arr.size();i++){
        if(i%2==0){
            for(int j =0;j<arr[0].size();j++)
        }
    }
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m,0));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    wavePrint(arr);
    return 0;
}