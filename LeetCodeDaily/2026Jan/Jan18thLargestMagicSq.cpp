#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> row(n, vector<int>(m, 0));
        vector<vector<int>> col(n, vector<int>(m, 0));

        vector<vector<int>> diag1(n, vector<int>(m, 0));
        vector<vector<int>> diag2(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i][j] = grid[i][j] + ((j > 0) ? row[i][j - 1] : 0);
                col[i][j] = grid[i][j] + ((j > 0) ? row[i - 1][j] : 0);
                diag1[i][j] = grid[i][j] + ((i > 0 && j > 0) ? diag1[i - 1][j - 1] : 0);
                diag2[i][j] = grid[i][j] + ((i > 0 && j < n - 1) ? diag2[i - 1][j + 1] : 0);
            }
        }

        int ans = 1;

        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i < n - k + 1; i++) {
                for (int j = 0; j < m - k + 1; j++) {
                    int r = i + k - 1;
                    int c = j + k - 1;

                    int target = row[i][c] - (j > 0 ? row[i][j - 1] : 0);
                    bool isValid = true;

                    for (int x = i; x <= r && isValid; ++x) {
                        int s = row[x][c] - (j > 0 ? row[x][j - 1] : 0);
                        if (s != target) isValid = false;
                    }

                    // Check all columns
                    for (int y = j; y <= c && isValid; ++y) {
                        int s = col[r][y] - (i > 0 ? col[i - 1][y] : 0);
                        if (s != target) isValid = false;
                    }

                    // Check diagonals
                    int d1 = diag1[r][c] - (i > 0 && j > 0 ? diag1[i - 1][j - 1] : 0);
                    int d2 = diag2[r][j] - (i > 0 && c + 1 < n ? diag2[i - 1][c + 1] : 0);

                    if (d1 != target || d2 != target) isValid = false;

                    if (isValid) ans = k;
                }
            }
        }
        return ans;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
