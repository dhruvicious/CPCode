#include <bits/stdc++.h>
using namespace std;

bool ratInMaze(vector<vector<char>>& maze, vector<vector<int>>& ans, int n,
               int m, int i, int j) {
    if (i == m - 1 && j == n - 1) {
        ans[i][j] = 1;
        for (vector<int>& vec : ans) {
            for (int& i : vec) {
                cout << i << " ";
            }
            cout << endl;
        }
        return true;
    }
    ans[i][j] = 1;

    if (j + 1 < m && maze[i][j + 1] != 'X') {
        if (ratInMaze(maze, ans, n, m, i, j + 1)) return true;
    }
    if (i + 1 < n && maze[i + 1][j] != 'X') {
        if (ratInMaze(maze, ans, n, m, i + 1, j)) return true;
    }
    ans[i][j] = 0;
    return false;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n;
    cin >> m >> n;
    vector<vector<char>> maze(m, vector<char>(n));
    for (auto& vec : maze) {
        for (auto& i : vec) {
            cin >> i;
        }
    }
    vector<vector<int>> ans(m, vector<int>(n));
    ratInMaze(maze, ans, n, m, 0, 0);

    return 0;
}