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
    bool isPowerOf2(int n) {
        int setBits = 0;
        while (n) {
            setBits += (n & 1);
            n >>= 1;
        }
        if (setBits == 1)
            return true;
        else
            return false;
    }

    bool isPowerOf2(int n) { 
        return (n > 0 && (n & (n - 1) == 1)); 
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