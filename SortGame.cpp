#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, n;
    cin >> x >> n;
    vector<pair<string, int>> arr(n);
    for (auto& x : arr) {
        cin >> x.first;
        cin >> x.second;
    }
    sort(arr.begin(), arr.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             if (a.second == b.second) {
                 return a.first < b.first;
             }
             return a.second > b.second;
         });

    for (auto& p : arr) {
        if (p.second >= x) {
            cout << p.first << " " << p.second << '\n';
        }
    }
    return 0;
}