#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    set<int> arr;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        arr.insert(m);
    }
    vector<int> a(arr.begin(), arr.end());
    sort(a.begin(), a.end());

    int m = a.size();
    vector<bool> covered(m, false);
    vector<long long> b;

    for (int i = 0; i < m; i++) {
        if (covered[i]) continue;
        long long value = a[i];
        b.push_back(value);

        long long curr = value;
        while (true) {
            if (curr > k) break;
            auto it = lower_bound(a.begin(), a.end(), curr);
            if (it != a.end() && *it == curr) {
                covered[distance(a.begin(), it)] = true;
            } else {
                cout << -1 << endl;
                return;
            }
            curr += value;
            if (curr > a.back()) {
                if (curr <= k) {
                    cout << -1 << endl;
                    return;
                }
                break;
            }
        }
    }
    cout << b.size() << endl;
    for (int i : b) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
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
