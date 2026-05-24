#include <iostream>
#include <queue>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void FileIO(char* inputFile, char* outputFile) {
#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

class Solution {
   public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int>   q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();

                if (node == n - 1) {
                    return steps;
                }

                for (auto next : mp[arr[node]]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                mp[arr[node]].clear();
                if (node - 1 >= 0 && !visited[node - 1]) {
                    visited[node - 1] = true;
                    q.push(node - 1);
                }
                if (node + 1 >= 0 && !visited[node + 1]) {
                    visited[node + 1] = true;
                    q.push(node + 1);
                }
            }
            steps++;
        }
        return -1;
    }
};

// argsV[0] -> executable name
// argsV[1] -> input file
// argsV[2] -> output file
int main(int argC, char* argsV[]) {
    fastIO();
    if (argC >= 3) {
        FileIO(argsV[1], argsV[2]);
    }

    return 0;
}
