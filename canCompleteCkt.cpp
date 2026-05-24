#include <iostream>
#include <stdio.h>

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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGAS  = 0;
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            totalGAS += gas[i];
            totalCost += cost[i];
        }

        if (totalCost > totalGAS) return -1;
        int startIndex = 0;
        int tank       = 0;

        for (int i = 0; i < n; i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                startIndex = i + 1;
                tank       = 0;
            }
        }
        return startIndex;
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
