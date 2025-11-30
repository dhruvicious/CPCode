#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
    unordered_map<int, int> freqMap;
    for (int& i : arr) freqMap[i]++;
    int ans = 0;
    for (auto [c, f] : freqMap) {
        ans += min(f, (f >= c) ? (f - c) : INT_MAX);
    }
    return ans;
}

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
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        cout << solve(arr) << '\n';
    }
    return 0;
}