#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int i, int j, int n, vector<vector<int>>& board) {
    for (int k = 0; k < i; k++) {
        if (board[k][j]) {
            return false;
        }
    }
    int ci = i, cj = j;
    while (i >= 0 && j >= 0) {
        if (board[i--][j--]) return false;
    }
    i = ci;
    j = cj;
    while (i >= 0 && j < n) {
        if (board[i--][j++]) return false;
    }
    return true;
}

void NQueens(vector<vector<int>>& board, int i, int n, int& count) {
    if (i == n) {
        count++;
        for (vector<int> vec : board) {
            for (int i : vec) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (isSafe(i, j, n, board)) {
            board[i][j] = 1;
            NQueens(board, i + 1, n, count);
            board[i][j] = 0;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int count = 0;
    vector<vector<int>> board(n, vector<int>(n, 0));
    NQueens(board, 0, n, count);
    cout << count;
    return 0;
}