#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<string> x;

   public:
    void solve(string ans, int n, int op, int cl) {
        if (ans.size() == 2 * n) {
            x.push_back(ans);
            return;
        }

        if (op < n) {
            solve(ans + '(', n, op + 1, cl);
        }
        if (op > cl) {
            solve(ans + ')', n, op, cl + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", n, 0, 0);
        return x;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution s;
    int n;
    cin >> n;
    vector<string> ans = s.generateParenthesis(n);

    for (string& a : ans) cout << a << endl;
    return 0;
}