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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c -= a;
        d -= b;
        a = 0;
        b = 0;
        // unreachable
        if (d < 0 || c > d) {
            cout << -1 << endl;
            continue;
        }
        // second quadrant
        if (c < 0) {
            cout << (2 * d + abs(c)) << endl;
        } else if (c == d) {
            cout << abs(c) << endl;
        } else {  // c < d
            cout << (abs(c - d) + abs(d)) << endl;
        }
    }
    return 0;
}
