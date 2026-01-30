#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int X_INDEX = 0, Y_INDEX = 1, L_INDEX = 2;

class Solution {
   public:
    double separateSquares(vector<vector<int>>& squares) {
        double yMax = 0, totalArea = 0;
        for (auto& sq : squares) {
            int y = sq[Y_INDEX], l = sq[L_INDEX];
            totalArea += (double) l * l;
            yMax = max(yMax, (double) y + l);
        }

        auto check = [&](double mid) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                int y = sq[Y_INDEX], l = sq[L_INDEX];
                if (y < mid) {
                    area += l * min(mid - y, (double) l);
                }
            }
            return area >= totalArea / 2;
        };

        double low = 0, high = yMax;
        double ESP = 1e-5;
        while (abs(high - low) > ESP) {
            double mid = low + (high - low) / 2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    }
};

int main() {
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n;
        vector<vector<int>> squares(n, vector<int>(3, 0));
        for (auto& vec : squares) {
            for (auto& i : vec) cin >> i;
        }
        cout << s.separateSquares(squares);
    }
    return 0;
}
