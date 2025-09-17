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
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxSQDiag = -1;
        int maxArea=0;

        for (auto& vec : dimensions) {
            long long SqDiag = 1LL * vec[0] * vec[0] + 1LL * vec[1] * vec[1];
            int area=vec[0]*vec[1];
            if (SqDiag > maxSQDiag || (SqDiag==maxSQDiag && area>maxArea)) {
                maxSQDiag = SqDiag;
                maxArea= area;
            }
        }
        return maxArea;
    }
};

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> dimensions = {{1, 10}, {3, 10}, {4, 4}, {2, 6}, {6, 3},
                                      {6, 4},  {9, 1},  {6, 1}, {2, 3}};
    Solution s;
    cout << s.areaOfMaxDiagonal(dimensions);
    return 0;
}