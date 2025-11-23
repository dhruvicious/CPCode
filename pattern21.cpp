#include <bits/stdc++.h>
using namespace std;

// *               *
// * *           * *
// * * *       * * *
// * * * *   * * * *
// * * * * * * * * *

void solveFor(int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            for (int j = 0; j < 2 * n - 1; j++) {
                cout << "* ";
            }
            i++;
            cout << endl;
        }
        int spaceCount = 2 * i - 1;
        int starCount = (2 * n - 1) - spaceCount;
        for (int i = 0; i < starCount / 2; i++) {
            cout << "* ";
        }
        for (int i = 0; i < spaceCount; i++) {
            cout << "  ";
        }
        for (int i = 0; i < starCount / 2; i++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    solveFor(n);
    return 0;
}