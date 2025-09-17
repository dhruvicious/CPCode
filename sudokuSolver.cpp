#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!IsSafe(board, i, j, 9, board[i][j])) return false;
                }
            }
        }
        return true;
    }

   private:
    bool IsSafe(vector<vector<char>>& arr, int i, int j, int n, char no) {
        int sn = sqrt(n);
        int si = (i / sn) * sn;
        int sj = (j / sn) * sn;

        for (int k = 0; k < n; k++) {
            if (k != i && arr[k][j] == no) return false;
            if (k != j && arr[i][k] == no) return false;
        }
        for (int k = si; k < si + sn; k++) {
            for (int l = sj; l < sj + sn; l++) {
                if ((k != i || l != j) && arr[k][l] == no) return false;
            }
        }
        return true;
    }
};

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    Solution s;
    if (s.isValidSudoku(board)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}