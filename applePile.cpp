#include <iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (n == k) {
            cout << 0 << endl;
            continue;
        }

        int ans = -1;
        for (int i = 1; i <= 31; ++i) {
            long long pow = 1LL << i;
            long long l = n / pow;
            long long h = (n + pow - 1) / pow;

            if (l == k || h == k) {
                ans = i;
                break;
            }

            if (h < k) break;
        }
        cout << ans << endl;
    }
    return 0;
}
