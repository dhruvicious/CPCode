#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = 0;
        int empty = 0;

        while (numBottles > 0) {
            totalDrunk += numBottles;
            empty += numBottles;
            numBottles = 0;
            while (empty >= numExchange) {
                empty -= numExchange;
                numBottles += 1;
                numExchange += 1;
            }
        }
        return totalDrunk;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}