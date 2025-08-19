#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void toggleCase(string& s) {
    for (char& c : s) {
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
        } else if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }
    }
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin, s);
    toggleCase(s);
    cout << s;
    return 0;
}