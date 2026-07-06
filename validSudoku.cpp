#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    bool isSafe(vector<vector<char>>& board, int i, int j, int n, char no) {
        int sn = sqrt(n);
        int si = (i / sn) * sn;
        int sj = (j / sn) * sn;

        for (int k = 0; k < n; k++) {
            if (k != i && board[k][j] == no) {
                return false;
            }
            if (k != j && board[i][k] == no) {
                return false;
            }
        }
        for (int k = si; k < si + sn; k++) {
            for (int l = sj; l < sj + sn; l++) {
                if ((k != i || l != j) && board[k][l] == no) {
                    return false;
                }
            }
        }
        return true;
    }

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!isSafe(board, i, j, 9, board[i][j])) return false;
                }
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
