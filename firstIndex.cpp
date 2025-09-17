#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int helper(vector<int> arr, int target, int i){
    if(i == arr.size()) return -1;
    if(arr[i]==target) return i;
    return helper(arr, target, i+1);
}

int firstIndex(vector<int> arr, int target){
    return helper(arr, target, 0);
}

int32_t main() {
    fastio
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n; cin>>n;
    vector<int> arr(n);
    for(auto& num:arr) cin>>num;
    int m; cin>>m;

    cout<<firstIndex(arr, m)<<endl;
    return 0;
}