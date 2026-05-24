#include <cmath>
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
        int n;
        cin >> n;
        if (n < 10) {
            cout << n << '\n';
            continue;
        } else {
            int digits  = log10(n) + 1;
            int power10 = pow(10, digits - 1);
            int leading = n / power10;

            int ans = 9 * (digits - 1) + leading;
            cout << ans << '\n';
        }
    }

    return 0;
}
