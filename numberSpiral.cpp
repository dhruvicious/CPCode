#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void numberSpiral(ll X, ll Y) {
    if (Y > X) {
        ll ans = (Y - 1) * (Y - 1);
        ll add = 0;

        if (Y % 2 != 0) {
            add = X;
        }
        else {
            add = 2 * Y - X;
        }
        cout << ans + add << "\n";
    }
    else {
        ll ans = (X - 1) * (X - 1);
        ll add = 0;

        if (X % 2 == 0) {
            add = Y;
        }
        else {
            add = 2 * X - Y;
        }
        cout << ans + add << "\n";
    }
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin>>t;
    while (t--) {
        ll x, y;
        cin >> y >> x;
        numberSpiral(x,y);
    }
    return 0;
}