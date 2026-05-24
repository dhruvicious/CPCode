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
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxWater = 0;
        while (left < right) {
            int width     = abs(right - left);
            int minheight = min(height[left], height[right]);
            int currWater = width * minheight;
            maxWater      = currWater > maxWater ? currWater : maxWater;
            if (height[right] < height[left])
                right--;
            else
                left++;
        }
        return maxWater;
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
