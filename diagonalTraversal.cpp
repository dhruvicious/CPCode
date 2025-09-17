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
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> result;
        result.reserve(m * n);
        for (int d = 0; d < m + n - 1; d++) {
            vector<int> temp;
            int r = d < m ? 0 : d - m + 1;
            int c = d < m ? d : m - 1;

            while(r<n && c>=0){
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }

            if(d%2==0){
                reverse(temp.begin(), temp.end());
            }
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    Solution s;
    s.findDiagonalOrder(mat);
    return 0;
}