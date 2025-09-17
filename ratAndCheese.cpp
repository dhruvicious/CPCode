#include <bits/stdc++.h>
using namespace std;

bool ratInMaze(vector<vector<char>>& maze, int i, int j, int n, int m,
               vector<vector<int>>& result) {
    // Base case: destination reached
    if (i == n - 1 && j == m - 1 && maze[i][j] == 'O') {
        result[i][j] = 1;
        return true;
    }

    // Check boundaries and blocked cells
    if (i < 0 || j < 0 || i >= n || j >= m || maze[i][j] == 'X') return false;

    if (result[i][j] == 1) return false;  // already visited

    // Mark current cell as part of path
    result[i][j] = 1;

    // Move Right
    if (ratInMaze(maze, i, j + 1, n, m, result)) return true;

    // Move Down
    if (ratInMaze(maze, i + 1, j, n, m, result)) return true;

    // Move Left
    if (ratInMaze(maze, i, j - 1, n, m, result)) return true;

    // Move Up
    if (ratInMaze(maze, i - 1, j, n, m, result)) return true;

    // Backtrack
    result[i][j] = 0;
    return false;
}

int32_t main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    vector<vector<int>> result(n, vector<int>(m, 0));

    if (ratInMaze(maze, 0, 0, n, m, result)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO PATH FOUND";
    }

    return 0;
}