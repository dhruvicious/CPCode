#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);

void solve(long long n, long long a, long long b){
    int m = max(a,b);
    int mid=(n+1)/2;

    if(m<=mid){
        cout<<"YES\n";
    }else if(a==n || b==n){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        solve(n,a,b);
    }
    // Input
    //  7
    //  5 3 1
    //  4 1 2
    //  7 7 4
    //  8 3 7
    //  1 1 1
    //  1000000000 1000000000 1000000000
    //  3 2 1
    // Expected Output
    // YES YES NO NO YES YES NO
    // Actual Output
    // Yes Yes No No Yes No Yes
    return 0;
}