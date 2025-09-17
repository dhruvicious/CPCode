#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void solve(string& s, int index, vector<string>& ans) {
    if (index == s.size()) {
        ans.push_back(s);
        return;
    }
    if (s[index] == '?') {
        s[index] = '0';
        solve(s, index + 1, ans);

        s[index] = '1';
        solve(s, index + 1, ans);

        s[index] = '?';
    } else {
        solve(s, index + 1, ans);
    }
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<string> answer;
        solve(s, 0, answer);
        for (string s : answer) {
            cout << s << " ";
        }
    }
    return 0;
}