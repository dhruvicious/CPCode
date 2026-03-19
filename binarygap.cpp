#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    int binaryGap(int n) {
        int cpy_n = n;
        vector<bool> binaryrep;
        for (int i = 0; i < 32; i++) {
            binaryrep.push_back(cpy_n & 1);
            cpy_n >>= 1;
        }
        reverse(binaryrep.begin(), binaryrep.end());
        int prevIdx = -1;
        int maxgap = 0;

        for (int i = 0; i < 32; i++) {
            if (binaryrep[i] == 1) {
                if (prevIdx == -1) {
                    prevIdx = i;
                } else {
                    int gap = i - prevIdx;
                    maxgap = gap > maxgap ? gap : maxgap;
                    prevIdx = i;
                }
            }
        }
        return maxgap;
    }
};
