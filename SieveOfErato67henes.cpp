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
        bool found67 = false;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val == 67) found67 = true;
        }
        cout << (found67 ? "Yes\n" : "No\n");
    }
    return 0;
}
