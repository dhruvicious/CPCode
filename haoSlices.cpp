#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        int pizza;
        cin >> pizza;
        cout << (pizza - 1) / 2 << '\n';
    }
    return 0;
}