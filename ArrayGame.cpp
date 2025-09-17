#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

int solve(vector<int>& a, int l, int r) {
    if (l >= r) return 0;
    long long total = 0;
    for (int i = l; i <= r; i++) total += a[i];
    if (total % 2 != 0) return 0;

    long long prefix = 0;
    for (int i = l; i < r; i++) {
        prefix += a[i];
        if (prefix * 2 == total) {
            return 1 + max(solve(a, l, i), solve(a, i + 1, r));
        }
    }
    return 0;
}

int32_t main() {
    fastio
// #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t; cin >> t;
    while (t--){
        int N; cin>>N;
        vector<int> a(N);
        for(int i =0;i<N;i++) cin>>a[i];
        cout<<solve(a, 0, N-1)<<endl;
    }
    return 0;
}