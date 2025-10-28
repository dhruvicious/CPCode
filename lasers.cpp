#include <iostream>
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
    int t;
    cin >> t;
    while (t--) {
        int count = 0;
        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a > 0 && a < y) count++;
        }
        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;
            if (b > 0 && b < x) count++;
        }
        cout << count << endl;
    }
    return 0;
}