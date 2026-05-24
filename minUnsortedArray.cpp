#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   public:
    int findUnSortedSubarray(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < n; i++) {
            pq.push({arr[i], i});
        }
        int sortedIdx = 0;
        int left = INT_MAX, right = INT_MIN;

        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();

            if (curr.second != sortedIdx) {
                left  = min(left, curr.second);
                right = max(right, curr.second);
            }
            sortedIdx++;
        }
        if (left == INT_MAX) return 0;
        return right - left + 1;
    }

    int findUnsortedSubarray(vector<int>& nums) {
        int n    = nums.size();
        int left = -1, right = -1;
        int minS = nums[n - 1], maxS = nums[0];

        // find right Boundary
        for (int i = 1; i < n; i++) {
            maxS = ((maxS < nums[i])) ? nums[i] : maxS;
            if (nums[i] < maxS) right = i;
        }
        // find left bounday
        for (int i = n - 2; i >= 0; i--) {
            minS = minS < nums[i] ? minS : nums[i];
            if (nums[i] > minS) left = i;
        }
        if (right == -1) return 0;
        return right - left + 1;
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
        int         n;
        vector<int> arr = {2, 6, 4, 8, 10, 9, 15};
        // for (int& i : arr) cin >> i;
        s.findUnsortedSubarray(arr);
    }
    return 0;
}
