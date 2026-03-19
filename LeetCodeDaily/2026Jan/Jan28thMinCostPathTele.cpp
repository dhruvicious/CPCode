#include <algorithm>
#include <climits>
#include <cstdio>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

void fastIO() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
}

void IO(int argCount, char* argsValue[]) {
#ifndef ONLINE_JUDGE
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";
    if (argCount >= 3) {
        inputFile = argsValue[1];
        outputFile = argsValue[2];
    }
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

// struct State {
//     int cost;
//     int i, j, t;
//     bool operator>(const State& other) const { return cost > other.cost; }
// };
// class Solution {
//    public:
//     int minCost(std::vector<std::vector<int>>& grid, int k) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int INF = 1e9;
//         std::vector<std::vector<std::vector<int>>> dp(
//             n, std::vector<std::vector<int>>(m, std::vector<int>(k + 1, INF)));
//         std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

//         dp[0][0][0] = grid[0][0];
//         pq.push({grid[0][0], 0, 0, 0});

//         while (!pq.empty()) {
//             State curr = pq.top();
//             pq.pop();

//             int cost = curr.cost;
//             int i = curr.i;
//             int j = curr.j;
//             int t = curr.t;

//             if (cost != dp[i][j][t]) continue;
//             if (j + 1 < m) {
//                 int newCost = cost + grid[i][j + 1];
//                 if (newCost < dp[i][j + 1][t]) {
//                     dp[i][j + 1][t] = newCost;
//                     pq.push({newCost, i, j + 1, t});
//                 }
//             }
//             if (i + 1 < n) {
//                 int newCost = cost + grid[i + 1][j];
//                 if (newCost < dp[i + 1][j][t]) {
//                     dp[i + 1][j][t] = newCost;
//                     pq.push({newCost, i + 1, j, t});
//                 }
//             }

//             if (t < k) {
//                 for (int x = 0; x < n; x++) {
//                     for (int y = 0; y < m; y++) {
//                         if (grid[x][y] <= grid[i][j]) {
//                             int newCost = cost;
//                             if (newCost < dp[x][y][t + 1]) {
//                                 dp[x][y][t + 1] = newCost;
//                                 pq.push({newCost, x, y, t + 1});
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         int ans = INF;
//         for (int t = 0; t <= k; t++) {
//             ans = std::min(ans, dp[n - 1][m - 1][t]);
//         }

//         return ans;
//     }
// };
//
//
class Solution {
   public:
    int minCost(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(), [&](const auto& p1, const auto& p2) -> bool {
            return grid[p1.first][p1.second] < grid[p2.first][p2.second];
        });
        std::vector<std::vector<int>> costs(m, std::vector<int>(n, INT_MAX));
        for (int t = 0; t <= k; t++) {
            int minCost = INT_MAX;
            for (int i = 0, j = 0; i < points.size(); i++) {
                minCost = std::min(minCost, costs[points[i].first][points[i].second]);
                if (i + 1 < points.size() &&
                    grid[points[i].first][points[i].second] == grid[points[i + 1].first][points[i + 1].second]) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    costs[points[r].first][points[r].second] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i][j] = std::min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        costs[i][j] = std::min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};

int main(int argCount, char* argsValue[]) {
    fastIO();
    IO(argCount, argsValue);
    
    int t;
    std::cin >> t;
    Solution s;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::vector<int>> vec(n, std::vector<int>(m, 0));
        for (std::vector<int>& row : vec) {
            for (int& val : row) std::cin >> val;
        }
        s.minCost(vec, k);
    }
}
