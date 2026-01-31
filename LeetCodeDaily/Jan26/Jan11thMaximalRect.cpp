#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   private:
    int largestHistRect(vector<int> hist) {
        stack<int> st;
        int maxArea = 0;
        int n = hist.size();

        for (int i = 0; i <= n; i++) {
            int currH = (i == n ? 0 : hist[i]);

            while (!st.empty() && currH < hist[st.top()]) {
                int h = hist[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

   public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            maxArea = max(maxArea, largestHistRect(heights));
        }
        return maxArea;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> matrix(n, vector<char>(m));
        for (auto& vec : matrix) {
            for (auto& i : vec) {
                cin >> i;
            }
        }
        s.maximalRectangle(matrix);
    }

    return 0;
}
