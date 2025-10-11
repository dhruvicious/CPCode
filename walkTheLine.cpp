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
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> S(n);
        for (long long &num : S) cin >> num;

        if (n == 1) {
            cout << (S[0] <= k ? "YES\n" : "NO\n");
            continue;
        }

        long long Smin = *min_element(S.begin(), S.end());
        long long total = (2LL * n - 3) * Smin;
        cout << (total <= k ? "YES\n" : "NO\n");
    }
    return 0;
}