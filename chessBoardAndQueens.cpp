#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>>& board, int i, int j) {
    for (int k = 0; k < i; k++) {
        if (board[k][j] == 'Q') return false;
    }
    int ci = i, cj = j;
    while (i >= 0 && j >= 0) {
        if (board[i--][j--] == 'Q') {
            return false;
        }
    }
    i = ci;
    j = cj;
    while (i >= 0 && j < 8) {
        if (board[i--][j++] == 'Q') {
            return false;
        }
    }
    return true;
}

void countPlacements(vector<vector<char>>& board, int i, int& count) {
    if (i == 8) {
        count++;
        return;
    }
    for (int j = 0; j < 8; j++) {
        if (isSafe(board, i, j) && board[i][j] != '*') {
            board[i][j] = 'Q';
            countPlacements(board, i + 1, count);
            board[i][j] = '.';
        }
    }
}

int main() {
    vector<vector<char>> board(8, vector<char>(8, '.'));
    for (vector<char>& vec : board) {
        for (char& c : vec) {
            cin >> c;
        }
    }
    int count = 0;
    countPlacements(board, 0, count);
    cout << count << '\n';
}
