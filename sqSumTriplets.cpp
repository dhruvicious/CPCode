#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int NaiveQuadcountTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b < n; b++) {
                int c2 = a * a + b * b;
                int c = sqrt(c2);
                if (c * c == c2 && c <= n) {
                    count++;
                }
            }
        }
        return count;
    }

    int countTriples(int n) {
        int count = 0;
        for (int m = 2; m * m <= n; m++) {
            for (int p = 1; p < m; p++) {
                if (gcd(m, p) == 1 && ((m - p) % 2 == 1)) {
                    int c = m * m + p * p;
                    if (c > n) continue;
                    int a = m * m - p * p;
                    int b = 2 * m * p;

                    int k = 1;
                    while (k * c <= n) {
                        int A = k * a;
                        int B = k * b;
                        int C = k * c;
                        if (A <= n && B <= n) {
                            if (A != B)
                                count += 2;
                            else
                                count += 1;
                        }
                        k++;
                    }
                }
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
