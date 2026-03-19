#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

static const int MOD = 1e9 + 7;

class Solution {
   private:
    bool isValid(vector<vector<int>>& grid, int r, int c, int color) {
        if (c > 0 && grid[r][c - 1] == color) return false;
        if (r > 0 and grid[r - 1][c] == color) return false;
        return true;
    }

   public:
    // logic building part worked it up for understanding
    int numOfWaysBackTracking(int n) {
        vector<vector<int>> grid(n, vector<int>(3, -1));
        function<int(int, int)> backtrack = [&](int r, int c) -> int {
            // baseCase Row reaches n
            if (r == n) {
                return 1;
            }
            // baseCase Col reaches 3
            if (c == 3) {
                return backtrack(r + 1, 0);
            }
            long long ways = 0;
            for (int color = 0; color < 3; color++) {
                if (isValid(grid, r, c, color)) {
                    grid[r][c] = color;
                    ways = (ways + backtrack(r, c + 1)) % MOD;
                    grid[r][c] = -1;
                }
            }
            return static_cast<int>(ways);
        };
        return backtrack(0, 0);
    }

    int numOfWays(int n) {
        long long aba = 6;
        long long abc = 6;

        for (int i = 1; i < n; i++) {
            long long nextABA = (3 * aba + 2 * abc) % MOD;
            long long nextABC = (2 * aba + 2 * abc) % MOD;
            aba = nextABA;
            abc = nextABC;
        }
        return (aba + abc) % MOD;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    Solution s;
    cout << s.numOfWays(n);
    return 0;
}
