#include <algorithm>
#include <iostream>

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
        long long x;
        cin >> n >> x;

        long long sumFr = 0;
        long long maxCEff = -4e18;

        for (int i = 0; i < n; i++) {
            long long a, b, c;
            cin >> a >> b >> c;

            sumFr += a * (b - 1);
            long long currEff = (a * b) - c;
            maxCEff = max(maxCEff, currEff);
        }

        if (sumFr >= x) {
            cout << "0\n";
            continue;
        }
        if (maxCEff <= 0) {
            cout << "-1\n";
            continue;
        }

        long long def = x - sumFr;
        long long chodBhagda = (def + maxCEff - 1) / maxCEff;
        cout << chodBhagda << "\n";
    }
    return 0;
}
