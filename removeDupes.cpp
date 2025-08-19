#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

string removeDupes(string s) {
    int read = 0, write = 1;
    string ans;
    ans += s[0];
    while (read < s.size()) {
        if (s[read] == ans[write - 1]) {
            read++;
        } else {
            ans += s[read];
            read++;
            write++;
        }
    }
    return ans;
}

int32_t main() {
    fastio
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    string s;
    getline(cin, s);
    cout << removeDupes(s);
    return 0;
}