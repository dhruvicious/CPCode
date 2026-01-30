#include <algorithm>
#include <cstdio>
#include <iostream>
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
        int n, h, l;
        cin >> n >> h >> l;
        vector<int> a(n);
        for (int& i : a) cin >> i;

        int minD = min(h, l);
        int maxD = max(h, l);

        int countV = 0;
        int countS = 0;

        for (int val : a) {
            if (val > maxD) {
                continue;
            } else if (val <= minD) {
                countV++;
            } else {
                countS++;
            }
        }

        int spec = min(countS, countV);
        int rem = countV - spec;
        int pairsV = rem / 2;

        cout << (spec + pairsV) << '\n';
    }

    return 0;
}
