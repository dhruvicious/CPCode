#include <bits/stdc++.h>
using namespace std;

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
        vector<int> nums(n);

        for (int& i : nums) {
            cin >> i;
        }

        int maxElement = INT_MIN;
        for (int i : nums) {
            maxElement = i > maxElement ? i : maxElement;
        }
        cout << maxElement << " ";
    }
    return 0;
}