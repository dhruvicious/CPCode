#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minMoves(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int minMoves = 0;
        for (int& i : nums) {
            minMoves += abs(max - i);
        }

        return minMoves;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> vec = {4, 4, 5};
    Solution s;
    cout << s.minMoves(vec);
    return 0;
}