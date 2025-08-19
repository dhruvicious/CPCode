#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
const int MOD = 1e9 + 7;

class Solution {
   public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int i = 0;
        vector<int> powers;
        vector<int> ans;
        while (n) {
            if (n & 1) {
                powers.push_back(1 << i);
            }
            i++;
            n >>= 1;
        }
        for (auto& query : queries) {
            long long product = 1;
            for (int i = query[0]; i <= query[1]; i++) {
                product = (1LL * product * powers[i]) % MOD;
            }
            ans.push_back(product);
        }
        return ans;
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