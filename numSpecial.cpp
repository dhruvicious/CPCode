#include <vector>

using namespace std;

class Solution {
   public:
    int numSpecial(vector<vector<int>>& mat) {
        int         n = mat.size();
        int         m = mat[0].size();
        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (mat[row][col] == 1) {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }
        int ans = 0;
        for (int row = 0; row < n; row++) {
            if (rowCount[row] != 1) continue;
            for (int col = 0; col < m; col++) {
                if (mat[row][col] == 1 && rowCount[row] == 1
                    && colCount[col] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
