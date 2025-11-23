#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void solve() {}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        int ao = 0, bo = 0;
        int lastmisMatch = -1;

        for (int i = 1; i <= n; i++) {
            ao ^= a[i];
            bo ^= b[i];
            if (a[i] != b[i]) {
                lastmisMatch = i;
            }
        }

        if (ao == bo) {
            cout << "Tie\n";
            continue;
        }
        if (lastmisMatch == -1) {
            if (ao > bo) {
                cout << "Ajisai\n";
            } else {
                cout << "Mai\n";
            }
        } else {
            if (lastmisMatch % 2 == 1) {
                cout << "Ajisai\n";
            } else {
                cout << "Mai\n";
            }
        }
    }
    return 0;
}