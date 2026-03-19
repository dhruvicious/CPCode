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
        long long p, q;
        cin >> p >> q;

        if (3 * p == 2 * q) {
            cout << "BOB" << endl;
            continue;
        }

        long long maxK = min(p / 2, q / 3);
        if (maxK == 0) {
            cout << "ALICE" << endl;
            continue;
        }

        long long sum = q + p;
        if (sum % 2 == 0) {
            cout << "BOB\n";
        } else {
            if (maxK >= 2) {
                cout << "BOB\n";
            } else {
                cout << "ALICE" << endl;
            }
        }
    }
}
