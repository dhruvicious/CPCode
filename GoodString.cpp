#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

int GoodString(string& s) {
    int left = 0, right = 0;
    int maxlen = 0;
    while (right < s.size()) {
        if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
            s[right] == 'o' || s[right] == 'u') {
            right++;
        } else {
            int len = right - left-1;
            maxlen = max(maxlen, len);
            left = right;
            right++;
        }
        maxlen=max(maxlen, right-left);
    }
    return maxlen;
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    getline(cin, s);
    cout << GoodString(s);
    return 0;
}