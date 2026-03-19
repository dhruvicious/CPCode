#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        int mins = 0;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int s = q.size();
            bool infected = false;
            for (int i = 0; i < s; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto [d1, d2] : dirs) {
                    int newrow = row + d1;
                    int newcol = col + d2;

                    if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1) {
                        grid[newrow][newcol] = 2;
                        q.push({newrow, newcol});
                        freshCount--;
                        infected = true;
                    }
                }
            }
            if (infected) mins++;
        }
        return freshCount == 0 ? mins : -1;
    }
};
