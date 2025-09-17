#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void TOH(int n, char src, char helper, char dest) {
    if (!n) return;
    TOH(n - 1, src, dest, helper);
    cout << "Moving ring " << n << " from " << src << " to " << dest << endl;
    TOH(n - 1, helper, src, dest);
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    TOH(n, 'A', 'B', 'C');
    return 0;
}