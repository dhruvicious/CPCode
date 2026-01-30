#include <cstdio>
#include <iostream>
#include <string>

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
        string s;
        cin >> s;

        int oCount = 0;
        int maxlen = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                oCount++;
            } else {
                if (oCount >= 2) {
                    maxlen = n - 2;
                    break;
                }
            }
        }
        cout << maxlen << '\n';
    }
    return 0;
}
