#include <bits/stdc++.h>
using namespace std;

bool check(string x, string s);

bool check(string x, string s) {
    if (x.size() < s.size()) return false;
    return x.contains(s);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        string x1 = x + x;
        string x2 = x1 + x1;
        string x3 = x2 + x2;
        string x4 = x3 + x3;
        string x5 = x4 + x4;

        if (check(x, s)) {
            cout << 0 << endl;
        } else if (check(x1, s)) {
            cout << 1 << endl;
        } else if (check(x2, s)) {
            cout << 2 << endl;
        } else if (check(x3, s)) {
            cout << 3 << endl;
        } else if (check(x4, s)) {
            cout << 4 << endl;
        } else if (check(x5, s)) {
            cout << 5 << endl;
        } else {
            cout << -1 << endl;
        }
        continue;
    }
    return 0;
}