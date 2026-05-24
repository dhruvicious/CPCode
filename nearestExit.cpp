#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';
        int steps                      = 0;

        const vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int s = q.size();
            steps++;
            for (int i = 0; i < s; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int newRow = row + dir[d][0];
                    int newCol = col + dir[d][1];

                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)
                        continue;
                    if (maze[newRow][newCol] == '+') continue;
                    if (newRow == 0 || newRow == n - 1 || newCol == 0
                        || newCol == m - 1)
                        return steps;
                    maze[newRow][newCol] = '+';
                    q.push({newRow, newCol});
                }
            }
        }
        return -1;
    }
};

int main(){return 0}
