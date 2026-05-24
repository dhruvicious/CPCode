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

void FileIO(char* inputFile, char* outputFile) {
#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        queue<int>   q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int jumps = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                int currIndex = q.front();
                q.pop();

                if (currIndex == n - 1) {
                    return jumps;
                }

                for (int next = currIndex + 1;
                     next < currIndex + nums[currIndex]; next++) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            jumps++;
        }

        return -1;
    }

    int jumps(vector<int>& nums) {
        int jumps    = 0;
        int currEnd  = 0;
        int farthest = 0;
        int n        = nums.size() - 1;

        for (int i = 0; i < n; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }
        return jumps;
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
