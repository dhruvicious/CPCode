#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;

        int L = 0;
        int countK = 0;
        bool ok = false;

        for (int R = 0; R < n; R++) {
            if (arr[R] == k) countK++;
            int len = R - L + 1;
            int s = 2 * countK - len;

            while (L <= R && s <= 0) {
                if (arr[L] == k) countK--;
                L++;
                len = R - L + 1;
                s = 2 * countK - len;
            }
            if (s > 0) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}