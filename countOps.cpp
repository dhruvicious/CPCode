#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while (num1 != 0 || num2 != 0) {
            if (num1 >= num2) {
                num1 -= num2;
                count++;
            } else if (num2 >= num1) {
                num2 -= num1;
                count++;
            }
        }
        return count;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}