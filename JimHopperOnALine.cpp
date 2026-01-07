#include <iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 0;
    cin >> t;
    while (t--) {
        int x, k;
        cin >> x >> k;

        if (x % k != 0) {
            cout << 1 << endl;
            cout << x << endl;
        } else {
            cout << 2 << endl;
            cout << 1 << " " << x - 1 << endl;
        }
    }
    return 0;
}
