#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> rows(row, 1);
        vector<int> cols(col, 1);

        for (int rc = 0; rc < row; rc++) {
            for (int cc = 0; cc < col; cc++) {
                if (matrix[rc][cc] == 0) {
                    rows[rc] = 0;
                    cols[cc] = 0;
                }
            }
        }

        for (int rc = 0; rc < row; rc++) {
            for (int cc = 0; cc < col; cc++) {
                if (rows[rc] == 0 || cols[cc] == 0) {
                    matrix[rc][cc] = 0;
                }
            }
        }
    }
};

int main() {
    return 0;
}
