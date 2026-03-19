#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define vvi vector<vector<int>>
int x = 0, y = 1;
class Solution {
   public:
    long long largestSquareArea(vvi& bottomLeft, vvi& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a1 = bottomLeft[i][x], b1 = bottomLeft[i][y], c1 = topRight[i][x], d1 = topRight[i][y];
                int a2 = bottomLeft[j][x], b2 = bottomLeft[j][y], c2 = topRight[j][x], d2 = topRight[j][y];

                int xmin = max(a1, a2);
                int ymin = max(b1, b2);
                int xmax = min(c1, c2) w;
                int ymax = min(d1, d2);

                if (xmin < xmax && ymin < ymax) {
                    int width = xmax - xmin;
                    int height = ymax - ymin;

                    int side = min(width, height);
                    maxArea = max(maxArea, 1LL * side * side);
                }
            }
        }
        return maxArea;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
