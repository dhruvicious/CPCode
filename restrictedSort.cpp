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

void IO(int argsC, char* argsV[]) {
    const char* inputFile = (argsC >= 3) ? argsV[1] : "input.txt";
    const char* outputFile = (argsC >= 3) ? argsV[1] : "output.txt";

#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

int main(int argsC, char* argsV[]) {
    fastIO();
    IO(argsC, argsV);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int& i : arr) cin >> i;

        vector<int> s = arr;
        sort(s.begin(), s.end());

        int ans = INT_MAX;
        bool sortCheck = false;

        for (int i = 0; i < n; i++) {
            if (arr[i] != s[i]) {
                sortCheck = true;

                int constr = max(arr[i] - s[0], s.back() - arr[i]);
                ans = min(ans, constr);
            }
        }
        if (!sortCheck) cout << "-1\n";
        else cout << ans << '\n';
    }
}
