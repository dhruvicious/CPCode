#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void FastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void IO(char* inputFile, char* outputFile) {
#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix.begin(), matrix.end());
        }
    }
};

int main(int argC, char* argV[]) {
    FastIO();
    if (argC >= 3) {
        IO(argV[1], argV[2]);
    }
}
