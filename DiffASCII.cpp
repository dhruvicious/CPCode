#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

string diffASCII(string s) {
    if (s.size() < 2) return s;  // nothing to do
    string ans;
    for (int i = 0; i < s.size() - 1; i++) {
        int val = s[i] - s[i + 1];
        string st = to_string(val);
        ans.push_back(s[i]);
        ans.append(st);
    }
    ans.push_back(s.back());
    return ans;
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    getline(cin, s);
    cout << diffASCII(s);
    return 0;
}