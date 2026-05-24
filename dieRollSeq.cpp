#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void IO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main() {
    fastIO();
    IO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        vector<vector<int>> dp(n, vector<int>(6, INT_MAX));

        for (int j = 0; j < 6; j++) {
            int faceVal = j + 1;
            dp[0][j]    = (a[0] == faceVal) ? 0 : 1;
        }

        for (int i = 1; i < n; i++) {
            for (int curr = 0; curr < 6; curr++) {
                int currFace   = curr + 1;
                int changeCost = (a[i] == currFace) ? 0 : 1;

                for (int prev = 0; prev < 6; prev++) {
                    int  prevFace = prev + 1;
                    bool adjCheck =
                        (currFace != prevFace) && (currFace + prevFace != 7);
                    if (adjCheck) {
                        dp[i][curr] =
                            min(dp[i][curr], dp[i - 1][prev] + changeCost);
                    }
                }
            }
        }
        int minOps = INT_MAX;
        for (int j = 0; j < 6; j++) {
            minOps = min(minOps, dp[n - 1][j]);
        }

        cout << minOps << '\n';
    }
    return 0;
}
