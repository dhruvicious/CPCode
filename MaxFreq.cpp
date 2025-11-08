#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void solve() {}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    unordered_map<int, int> arrMap;
    for (int i : arr) arrMap[i]++;
    int maxf = INT_MIN;
    int maxval = INT_MIN;

    for (auto& v : arrMap) {
        if (v.second > maxf) {
            maxval = v.first;
            maxf = v.second;
        }
    }

    cout << maxval << endl;
    return 0;
}