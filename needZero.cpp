#include <cstdio>
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
        int XorA = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            XorA ^= x;
        }
        if (n % 2 == 0) {
            if (XorA == 0)
                cout << 3 << endl;
            else
                cout << -1 << endl;

        } else {
            cout << XorA << endl;
        }
    }
    return 0;
}
