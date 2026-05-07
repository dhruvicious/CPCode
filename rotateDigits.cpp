#include <iostream>

using namespace std;

class Solution {
   public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i < n; i++) {
            int  curr    = i;
            bool valid   = true;
            bool changed = false;

            while (curr > 0 && valid) {
                int digit = curr % 10;
                if (digit == 3 || digit == 4 || digit == 7)
                    valid = false;
                else if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                    changed = true;

                curr /= 10;
            }

            if (valid && changed) count++;
        }
        return count;
    }
};

int main() {
}
