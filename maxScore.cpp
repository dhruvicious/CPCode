#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
   public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums1[i], nums2[i]};
        }
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        long long selectSum = 0, maxScore = 0;

        for (auto& pair : pairs) {
            minHeap.push(pair.first);
            selectSum += pair.first;

            if (minHeap.size() > k) {
                selectSum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) {
                long long currScore = selectSum * pair.second;
                maxScore = max(maxScore, currScore);
            }
        }
        return maxScore;
    }
};

int main() {
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums1(n), nums2(n);
        for (int& i : nums1) cin >> i;
        for (int& i : nums2) cin >> i;
        int k;
        cin >> k;
        s.maxScore(nums1, nums2, k);
    }

    return 0;
}
