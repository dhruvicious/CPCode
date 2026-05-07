#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> apples(n);
    long long         total = 0;
    for (int& i : apples) {
        cin >> i;
        total += i;
    }

    long long ans = LLONG_MAX;
    for (int mask = 0; mask < (1 << apples.size()); mask++) {
        long long currTotal = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                currTotal += apples[i];
            }
        }
        long long diff = abs(total - 2 * currTotal);
        ans            = min(ans, diff);
    }
    cout << ans << '\n';
    return 0;
}
