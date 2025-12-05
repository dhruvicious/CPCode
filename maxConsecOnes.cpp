#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1s = 0;
        int currCount = 0;
        for (int i : nums) {
            if (i == 1) {
                currCount++;
            } else {
                max1s = max(max1s, currCount);
                currCount = 0;
            }
        }
        max1s = max(max1s, currCount);
        return max1s;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    Solution s;
    cout << s.findMaxConsecutiveOnes(arr);
    return 0;
}