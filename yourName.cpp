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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        string t;
        cin >> s;
        cin >> t;
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }
        for (char c : t) {
            freq[c - 'a']--;
        }
        bool ans = true;

        for (int f : freq) {
            if (f != 0) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}