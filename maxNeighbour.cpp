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

        if (n == 1) {
            cout << 1 << endl;
            continue;
        } else if (n == 2) {
            cout << 9 << endl;
            continue;
        } else if (n == 3 || n == 4) {
            cout << (4 * n * n) - n - 4 << endl;
            continue;
        } else {
            cout << 5 * n * n - 5 * n - 5 << endl;
            continue;
        }
    }
    return 0;
}