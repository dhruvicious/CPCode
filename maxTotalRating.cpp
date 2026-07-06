#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();

        for (int i = 0; i < m; i++) {
            sort(units[i].begin(), units[i].end());
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            minHeap;

        for (int i = 0; i < m; i++) {
            minHeap.push({units[i][0], i, 0});
        }

        int       availableTransfers = m;
        long long totalRatingSUM     = 0;

        while (!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();

            int currCap    = current[0];
            int deviceIndx = current[1];
            int unitIndex  = current[2];

            if (availableTransfers > 0 && unitIndex + 1 < n) {
                availableTransfers--;

                minHeap.push({units[deviceIndx][unitIndex + 1], deviceIndx,
                              unitIndex + 1});
            } else {
                totalRatingSUM += currCap;
            }
        }

        return totalRatingSUM;
    }
};

int main() {
}
