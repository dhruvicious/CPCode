#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int X = points[i][0];
            int Y = points[i][1];
            int Xn = points[i + 1][0];
            int Yn = points[i + 1][1];
            ans += max(abs(X - Xn), abs(Y - Yn));
        }
        return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n;
        vector<vector<int>> points(n, vector<int>(2, 0));
        for (vector<int>& vec : points) {
            for (int& i : vec) cin >> i;
        }
        cout << s.minTimeToVisitAllPoints(points) << endl;
    }
    return 0;
}
