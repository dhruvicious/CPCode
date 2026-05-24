#include <algorithm>
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
    int trap(vector<int> height) {
        int         n = height.size();
        vector<int> leftM(n, 0);
        vector<int> rightM(n, 0);

        rightM[n - 1] = height[n - 1];
        leftM[0]      = height[0];

        for (int i = 1; i < n; i++) {
            leftM[i]  = max({leftM[i - 1], height[i]});
            int j     = n - i - 1;
            rightM[j] = max(rightM[j + 1], height[j]);
        }

        int harvested = 0;
        for (int i = 0; i < n; i++) {
            harvested += max(0, min(leftM[i], rightM[i]) - height[i]);
        }

        return harvested;
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
