#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);

        sort(s.begin(), s.end());
        for (int i = 0; i < 31; i++) {
            int powerOf2 = 1 << i;
            string t = to_string(powerOf2);

            sort(t.begin(), t.end());

            if (t == s) return true;
        }

        return false;
    }
};

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}