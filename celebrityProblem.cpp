#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int candidate = 0;
    for (int i = 1; i < n; i++) {
        if (mat[candidate][i] == 1) candidate = i;
    }

    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;
        if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
            cout << "No Celebrity";
            return 0;
        }
    }
    cout << candidate;
    return 0;
}