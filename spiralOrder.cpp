#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        vector<int> ans;

        int m = mat.size();
        int n = mat[0].size();

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        int r = 0, c = 0;
        int d = 0;

        for (int i = 0; i < m * n; i++) {
            ans.push_back(mat[r][c]);
            mat[r][c] = INT_MAX;

            int nxtR = r + dr[d];
            int nxtC = c + dc[d];

            if (nxtR >= 0 && nxtR < m && nxtC >= 0 && nxtC < n
                && mat[nxtR][nxtC] != INT_MAX) {
                r = nxtR;
                c = nxtC;
            } else {
                d = (d + 1) % 4;
                r += dr[d];
                c += dc[d];
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> mat;

    for (vector<int>& vec : mat) {
        for (int& i : vec) {
            cin >> i;
        }
    }
}
