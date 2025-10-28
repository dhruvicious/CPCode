#include <iostream>
using namespace std;

class Solution {
   public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int remainDays = n % 7;
        int total = 0;

        for (int i = 0; i < weeks; i++) {
            total += (28 + (7 * i));
        }
        for (int i = 0; i < remainDays; i++) {
            total += weeks + 1 + i;
        }

        return total;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int n;
    cin >> n;
    Solution s;
    cout << s.totalMoney(n);
}