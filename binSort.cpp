#include <algorithm>
#include <bit>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int aBitCount = __builtin_popcount(a);
            int bBitCount = __builtin_popcount(b);

            if (aBitCount == bBitCount)
                return a < b;
            else
                return aBitCount < bBitCount;
        });
        return arr;
    } 
};

int main() {
}
