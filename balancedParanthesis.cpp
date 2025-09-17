#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void balancedParanthesis(int open, int close, int n, string& s) {
    if (open == 0 && close == 0) {
        cout << s << endl;
        return;
    }
    if (close > open) {
        s.push_back(')');
        balancedParanthesis(open, close - 1, n, s);
        s.pop_back();
    }
    if (open > 0) {
        s.push_back('(');
        balancedParanthesis(open - 1, close, n, s);
        s.pop_back();
    }
}

int32_t main() {
    fastio
// #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int n;
    cin >> n;
    string curr;
    balancedParanthesis(n, n, n, curr);
    return 0;
}