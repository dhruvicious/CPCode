#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long negativeCount = 0;
        long long modSum = 0;
        long long leastAbs = LLONG_MAX;
        for (vector<int>& vec : matrix) {
            for (int& i : vec) {
                modSum += llabs((long long)i);
                negativeCount += i < 0 ? 1 : 0;
                leastAbs = min(llabs((long long) i), leastAbs);
            }
        }
        return (negativeCount % 2 == 0) ? (modSum) : (modSum - 2 * leastAbs);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (vector<int>& vec : matrix) {
        for (int& i : vec) {
            cin >> i;
        }
    }
    Solution s;
    cout << s.maxMatrixSum(matrix);
    return 0;
}
