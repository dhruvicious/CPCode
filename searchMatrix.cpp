#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();

        int top = 0, down = numRows - 1;
        int validRow = -1;

        while (top <= down) {
            int mid = top + (down - top) / 2;
            if (matrix[mid][0] <= target && matrix[mid][numCols - 1] >= target) {
                validRow = mid;
                break;
            } else if (matrix[mid][0] > target) {
                down = mid - 1;
            } else {
                top = mid + 1;
            }
        }
        if (validRow == -1) return false;

        int left = 0, right = numCols - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[validRow][mid] == target) return true;
            else if (matrix[validRow][mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};

int32_t main() {
    Solution s;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (vector<int> &vec : mat) {
        for (int &val : vec) {
            cin >> val;
        }
    }
    int target;
    cin >> target;
    bool ans = s.searchMatrix(mat, target);
    if (ans) cout << 0;
    else cout << 1;
    return 0;
}