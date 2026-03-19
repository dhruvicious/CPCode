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
        int n;
        cin >> n;
        vector<int> arr(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        long long SN = (arr[1] + arr[n]) / (n - 1);
        vector<long long> S(n + 1);
        S[n] = SN;

        for (int x = 1; x < n; ++x) {
            long long diff = arr[x + 1] - arr[x];
            S[x] = (diff + SN) / 2;
        }

        vector<long long> a(n + 1);
        long long currPrevS = 0;

        for (int i = 1; i <= n; ++i) {
            a[i] = S[i] - currPrevS;
            currPrevS = S[i];
        }

        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
