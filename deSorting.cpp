#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        int ans = INT_MAX;
        if (is_sorted(arr.begin(), arr.end())) {
            cout << 0 << endl;
            continue;
        } else {
            for (int i = 0; i < n - 1; i++) {
                int diff = arr[i + 1] - arr[i];
                ans = min(ans, diff / 2 + 1);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
