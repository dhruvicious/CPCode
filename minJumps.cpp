#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#undef int
#define int long long

// Min Jumps Solution using backtracking
int minJumpsBacktracking(vector<int>& arr) {
    function<int(int)> backtrack = [&](int idx) -> int {
        int n = arr.size();
        if (idx >= n - 1) return 0;
        if (arr[idx] == 0) return INT_MAX;

        int minSteps = INT_MAX;
        for (int jump = 1; jump <= arr[idx] && idx + jump < n; jump++) {
            int nextIdx = idx + jump;
            int res = backtrack(nextIdx);
            if (res != INT_MAX) {
                minSteps = min(minSteps, 1 + res);
            }
        }
        return minSteps;
    };
    int result = backtrack(0);
    return (result == INT_MAX) ? -1 : result;
}

// Solution using top down DP
int MinJumpsTopDownDP(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, -1);

    function<int(int)> backtrack = [&](int idx) -> int {
        if (idx >= n - 1) return 0;

        if (dp[idx] != -1) return dp[idx];
        if (arr[idx] == 0) return dp[idx] = INT_MAX;

        int minSteps = INT_MAX;
        for (int jump = 1; jump <= arr[idx] && idx + jump < n; jump++) {
            int res = backtrack(idx + jump);
            if (res != INT_MAX) {
                minSteps = min(minSteps, 1 + res);
            }
        }
        return dp[idx] = minSteps;
    };
    int result = backtrack(0);
    return (result == INT_MAX) ? -1 : result;
}

// Solution using bottom up DP
int minJumpsBottomUpDP(vector<int>& arr) {
    int n = arr.size();
    const int INF = INT_MAX;
    vector<int> dp(n, INF);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        if (dp[i] == INF || dp[i] == 0) continue;
        for (int j = i + 1; j <= min(n - 1, arr[i] + i); j++) {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    return (dp[n - 1] == INF) ? -1 : dp[n - 1];
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        cout << MinJumpsTopDownDP(arr) << endl;
    }
    return 0;
}
