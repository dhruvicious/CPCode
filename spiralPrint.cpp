#include <climits>
#include <iostream>
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
    vector<int> spiralOrder2(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> flat;

        for (vector<int>& row : matrix) {
            for (int& idx : row) {
                flat.push_back(idx);
            }
        }

        vector<int> ans;

        vector<int> dir            = {1, n, -1, -n};
        int         stepHorizontal = n;
        int         stepVertical   = m - 1;

        int d   = 0;
        int idx = 0;

        while (stepHorizontal > 0 && stepVertical > 0) {
            int steps = (d % 2 == 0) ? stepHorizontal : stepVertical;

            for (int i = 0; i < steps; i++) {
                ans.push_back(flat[idx]);
                if (i != steps - 1) {
                    idx += dir[d];
                }
            }
            if (d == 0) stepHorizontal--;
            if (d == 1) stepVertical--;
            if (d == 2) stepHorizontal--;
            if (d == 3) stepVertical--;

            d = (d + 1) % 4;

            idx += dir[d];
        }

        if (ans.size() < flat.size()) {
            int remain = flat.size() - ans.size();

            for (int i = 0; i < remain; i++) {
                ans.push_back(flat[idx]);
                if (i != remain - 1) {
                    idx += dir[d];
                }
            }
        }
        return ans;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        int r = 0, c = 0;
        int d = 0;

        for (int i = 0; i < m * n; i++) {
            ans.push_back(matrix[r][c]);
            matrix[r][c] = INT_MAX;

            int nxtR = r + dr[d];
            int nxtC = c + dc[d];

            if (nxtR >= 0 && nxtR < m && nxtC >= 0 && nxtC < n
                && matrix[nxtR][nxtC] != INT_MAX) {
                r = nxtR;
                c = nxtC;
            } else {
                d = (d + 1) % 4;
                r += dr[d];
                c += dc[d];
            }
        }

        return ans;
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
