#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> solve(int a, int b) {
    if (a == b) return {0, {}};

    int x = a ^ b;
    if (x <= a) {
        return {1, {x}};
    }

    int m = a | b;
    int x1 = a ^ m;
    int x2 = m ^ b;

    if (x1 <= a && x2 <= m) {
        return {2, {x1, x2}};
    }

    return {-1, {}};
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        auto [k, ans] = solve(a, b);

        if (k == -1) {
            cout << -1 << '\n';
        } else {
            cout << k << '\n';
            if (k > 0) {
                for (int a : ans) {
                    cout << a << " ";
                }
                cout << '\n';
            }
        }
    }
    return 0;
}