#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
        vector<int> a(n);
        int count2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 2) count2++;
        }
        if (count2 % 2 != 0) {
            cout << "-1\n";
            continue;
        }
        int half = count2 / 2;
        int prefix2 = 0;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] == 2) {
                prefix2++;
            }
            if (prefix2 == half) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
