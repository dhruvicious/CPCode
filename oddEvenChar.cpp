#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void oddEven(string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {
            s[i] = s[i] + 1;
        } else {
            s[i] = s[i] - 1;
        }
    }
}

int32_t main() {
    fastio
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    string s;
    getline(cin, s);
    oddEven(s);
    cout << s;
    return 0;
}