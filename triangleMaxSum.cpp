#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    // int backtrack(vector<vector<int>> triangle, int row, int col) {
    //     if (row == triangle.size() - 1){
    //         return triangle[row][col];
    //     }
    //     int left = backtrack(triangle, row+1 , col);
    //     int right = backtrack(triangle, row+1, col+1);

    //     return triangle[row][col]+min(left, right);
    // }

   public:
    int minimumTotal(vector<vector<int>> &triangle) {
        // return backtrack(triangle, 0, 0);
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        return dp[0];
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}