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
    int q;
    cin >> q;
    stack<int> st;

    while (q--) {
        int type;
        cin >> type;
        if (type == 2) {
            long long cost;
            cin >> cost;
            st.push(cost);
        } else {
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            } else {
                cout << "No Code" << '\n';
            }
        }
    }
    return 0;
}