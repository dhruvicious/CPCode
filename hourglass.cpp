#include <algorithm>
#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long t;
    cin >> t;
    while (t--) {
        long long s, k, m;
        cin >> s >> k >> m;

        long long n = m / k;
        long long remain = m % k;

        if (s <= k) {
            if (remain == 0)
                cout << s << endl;
            else
                cout << max(0LL, s - remain) << endl;
        } else {
            if (n % 2 == 0) {
                cout << (s - remain) << endl;
            } else {
                cout << (k - remain) << endl;
            }
        }
    }
    return 0;
}
