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

    for (vector<int> &row : mat) {
        for (int &val : row) {
            cin >> val;
        }
    }
    bool isTriag = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat[i][j] != 0) {
                isTriag = false;
                break;
            }
        }
        if (!isTriag) break;
    }
    if(isTriag) cout<<"true";
    else cout<<"false";
    return 0;
}