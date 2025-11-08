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
        int l;
        cin >> l;
        vector<int> arr(l);

        for (int& i : arr) cin >> i;
        unordered_map<int, int> arrMap;
        for (int& i : arr) arrMap[i]++;
        int q;
        cin >> q;

        while (q--) {
            int qv;
            cin >> qv;
            cout << (arrMap[q] > 0 ? "Yes" : "No") << endl;
        }
    }
    return 0;
}