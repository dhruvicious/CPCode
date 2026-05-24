#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void FileIO(const char* inputFile, const char* outputFile) {
#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

class Solution {
   public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int>   q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (arr[node] == 0) {
                return true;
            }

            int left  = node - arr[node];
            int right = node + arr[node];

            if (left >= 0 && !visited[left]) {
                visited[left] = true;
                q.push(left);
            }
            if (right >= 0 && !visited[right]) {
                visited[right] = true;
                q.push(right);
            }
        }
        return false;
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
