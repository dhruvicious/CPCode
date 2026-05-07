#include <cstddef>
#include <vector>

using namespace std;

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n         = gas.size();
        int totalGas  = 0;
        int totalCost = 0;

        for (size_t i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if (totalGas < totalCost) return -1;

        int currGas = 0, startIndex = 0;

        for (int i = 0; i < n; i++) {
            currGas += gas[i] - cost[i];
            if (currGas < 0) {
                startIndex += 1;
                currGas = 0;
            }
        }
        return startIndex;
    }
};
