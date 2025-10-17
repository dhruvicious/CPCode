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
        cin >> n;
        vector<int> ops(n);
        for (int &i : ops) {
            cin >> i;
        }
        int size = 0;
        bool valid = true;
        for (int op : ops) {
            if (op == 1) {
                size++;
            } else {
                if (size == 0) {
                    valid = false;
                }
                size--;
            }
        }
        cout << (valid ? "Valid" : "Invalid") << endl;
    }
    return 0;
}