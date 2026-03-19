#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> TrailZero(n, 0);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                count++;
            }
            TrailZero[i] = count;
        }

        int swapCount = 0;
        for (int i = 0; i < n; i++) {
            int needZeroCount = n - i - 1;

            int j = i;  
            while (j < n && TrailZero[j] < needZeroCount) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(TrailZero[j], TrailZero[j - 1]);
                j--;
                swapCount++;
            }
        }
        return swapCount;
    }
};
