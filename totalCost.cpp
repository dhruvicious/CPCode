#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int                                            n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pqHead;
        priority_queue<int, vector<int>, greater<int>> pqTail;

        for (int i = 0; i < candidates; i++) {
            pqHead.push(costs[i]);
        }
        for (int i = max(candidates, n - candidates); i < n; i++) {
            pqTail.push(costs[i]);
        }

        long long ans      = 0;
        int       nextHead = candidates;
        int       nextTail = n - 1 - candidates;

        for (int i = 0; i < n; i++) {
            if (pqTail.empty()
                || !pqHead.empty() && pqHead.top() <= pqTail.top()) {
                ans += pqHead.top();
                pqHead.pop();
                if (nextHead <= nextTail) {
                    pqHead.push(costs[nextHead]);
                    nextHead++;
                }
            } else {
                ans += pqTail.top();
                pqTail.pop();
                if (nextHead <= nextTail) {
                    pqTail.push(costs[nextTail]);
                    nextTail--;
                }
            }
        }
        return ans;
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
        int n, k, candidates;
        cin >> n >> k >> candidates;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        cout << s.totalCost(arr, k, candidates);
    }
    return 0;
}
