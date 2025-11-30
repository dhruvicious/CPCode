#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
        for (int i : nums) sum += i;
        int remainder = sum % p;
        if (remainder == 0) return 0;

        int minLength = n;

        for (int start = 0; start < n; start++) {
            int subSum = 0;
            for (int end = start; end < n; end++) {
                subSum += nums[end];

                int remainSum = (sum - subSum) % p;
                if (remainSum == 0) {
                    minLength = min(minLength, end - start + 1);
                }
            }
        }
        return minLength == n ? -1 : minLength;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        int p;
        cin >> p;
        Solution s;
        cout << s.minSubarray(arr, p) << endl;
    }
    return 0;
}