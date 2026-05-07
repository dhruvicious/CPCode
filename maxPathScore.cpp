#include <iostream>
#include <vector>

// using namespace std;

// class Solution {
//    private:
//     int                         k;
//     int                         maxScore = -1;
//     vector<vector<vector<int>>> DP;
//     void backtrack(vector<vector<int>>& grid, int i, int j, int cost,
//                    int score) {
//         int m = grid.size();
//         int n = grid[0].size();

//         if (i >= m || j >= n) return;

//         cost += ((grid[i][j] == 0) ? 0 : 1);
//         score += grid[i][j];

//         if (cost > k) return;

//         if (DP[i][j][cost] >= score) return;
//         DP[i][j][cost] = score;

//         if (i == m - 1 && j == n - 1) {
//             maxScore = max(maxScore, score);
//             return;
//         }

//         backtrack(grid, i + 1, j, cost, score);
//         backtrack(grid, i, j + 1, cost, score);
//     }

//    public:
//     int maxPathScore(vector<vector<int>>& grid, int K) {
//         k        = K;
//         maxScore = -1;
//         DP.assign(grid.size(),
//                   vector<vector<int>>(grid[0].size(), vector<int>(k + 1,
//                   -1)));
//         backtrack(grid, 0, 0, 0, 0);
//         return maxScore;
//     }
// };
//
//
//
//
using namespace std;

class Solution {
   public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int startCost = (grid[0][0] == 0) ? 0 : 1;
        if (startCost <= k) {
            dp[0][0][startCost] = grid[0][0];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
            }
        }
    }
};

int main() {
    return 0;
}
