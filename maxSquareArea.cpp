#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hMax = 1, vMax = 1;
        int hCurr = 1, vCurr = 1;

        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hCurr++;
            } else {
                hCurr = 1;
            }
            hMax = max(hMax, hCurr);
        }
        for (int i = 1; i < vBars.size(); i++) {
            if (hBars[i] == vBars[i - 1] + 1) {
                vCurr++;
            } else {
                vCurr = 1;
            }
            vMax = max(vMax, vCurr);
        }
        int side = min(hMax, vMax) + 1;
        return side * side;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> hBars(n);
        vector<int> vBars(m);
        for (int& i : hBars) cin >> i;
        for (int& i : vBars) cin >> i;
        cout << s.maximizeSquareHoleArea(n, m, hBars, vBars);
    }

    return 0;
}
