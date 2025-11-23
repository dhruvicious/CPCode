#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long sumAndMultiply(int n) {
        vector<int> nums;
        int sum = 0;
        while (n) {
            sum += (n % 10);
            nums.push_back(n % 10);
            n = n / 10;
        }
        reverse(nums.begin(), nums.end());
        int x = 0;
        for (int i : nums) {
            if (i == 0)
                continue;
            else {
                x = x * 10 + i;
            }
        }
        return x*sum;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution s;
    cout<<s.sumAndMultiply(10203004);

    return 0;
}