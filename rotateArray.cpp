#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution {
   public:
    void rotate(vector<vi> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int j = 0; j < n; j++) {
            int top = 0, bottom = n - 1;
            while (top < bottom) {
                swap(matrix[top][j], matrix[bottom][j]);
                top++;
                bottom--;
            }
        }
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (vector<int> &row : mat) {
        for (int &val : row) {
            cin >> val;
        }
    }
    Solution s;
    s.rotate(mat);
    for (vector<int> &row : mat) {
        for (int &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}