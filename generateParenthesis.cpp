#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   private:
    void backtrack(int start, int end, int n, string currStr,
                   vector<string>& result) {
        if (start > n || end > n) return;
        if (start == n && end == n) {
            result.push_back(currStr);
            return;
        }

        if (start < n) {
            backtrack(start + 1, end, n, currStr + '(', result);
        }
        if (end < start) {
            backtrack(start, end + 1, n, currStr + ')', result);
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
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