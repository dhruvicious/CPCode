#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    int l = 0, r = 0;
    int maxLen = 0;
    int currLen = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            currLen++;
        else
            currLen = 0;
        maxLen = max(currLen, maxLen);
    }
    cout << maxLen << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
