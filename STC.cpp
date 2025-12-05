#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int sc = 0;
        int au = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                au = max(au, i + k);
            } else {
                if (i > au) {
                    sc++;
                }
            }
        }
        cout << sc << endl;
    }
    return 0;
}
