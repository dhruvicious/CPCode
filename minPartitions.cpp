#include <algorithm>
#include <climits>
#include <string>

using namespace std;

class Solution {
   public:
    int minPartitions(string n) {
        int maxEl = INT_MIN;
        for (char c : n) maxEl = max(maxEl, c - '0');
        return maxEl;
    }
};
