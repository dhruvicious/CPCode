#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(102, vector<double>(102, 0.0));
        tower[0][0] = poured;

        for (int r = 0; r <= query_row; r++) {
            for (int c = 0; c <= r; c++) {
                if (tower[r][c] > 1.0) {
                    double excess = (tower[r][c] - 1.0) / 2.0;
                    tower[r][c] = 1.0;
                    tower[r + 1][c] += excess;
                    tower[r + 1][c + 1] += excess;
                }
            }
        }
        return tower[query_row][query_glass];
    }

    double champagneTowerFastDp(int poured, int query_row, int query_glass) {
        vector<double> dp(query_row + 2, 0.0);
        dp[0] = (double)poured;
        for (int i = 1; i <= query_row; i++) {
            for (int j = i; j >= 0; j--) {
                dp[j + 1] += dp[j] = max((dp[j] - 1) / 2, 0.0);
            }
        }
        return min(dp[query_glass], 1.0);
    }
};

int main() {
}
