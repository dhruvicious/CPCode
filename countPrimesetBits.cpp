#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
   private:
    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    // int countSetBit(int n) {
    //     int count = 0;
    //     while (n) {
    //         if ((n & 1) == 1) count++;
    //         n >>= 1;
    //     }
    //     return count;
    // }

   public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (primes.count(__builtin_popcount(i))) count++;
        }
        return count;
    }
};

int main() {
    return 0;
}
