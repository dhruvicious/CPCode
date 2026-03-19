#include <climits>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
   public:
    int minPartitions(string n) {
        int maxEl = INT_MIN;
        for(char c: n) maxEl = max(maxEl, c-'0');
        return maxEl; 
    }
};
