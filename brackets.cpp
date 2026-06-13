#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push_back(i);
            } else {
                if (!st.empty()) {
                    st.pop_back();
                }
            }
        }

        int L1 = n;
        if (!st.empty()) {
            L1 = st[0];
        }

        vector<int> safeRemovals;
        for (int i = 0; i < n; i++) {
            if (i < L1 && s[i] == '(') {
                safeRemovals.push_back(i);
            } else if (i > L1 && s[i] == ')') {
                safeRemovals.push_back(i);
            }
        }

        string ans(n, '0');
        int    removeCount = min(k, (int) safeRemovals.size());
        for (int i = 0; i < removeCount; i++) {
            ans[safeRemovals[i]] = '1';
        }

        cout << ans << "\n";
    }
    return 0;
}
