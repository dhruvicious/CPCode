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
    int romanToInt(string s) {
        unordered_map<char, int> val = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && val[s[i]] < val[s[i + 1]]) {
                total-=val[s[i]];
            }else{
                total+=val[s[i]];
            }
        }
        return total;
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