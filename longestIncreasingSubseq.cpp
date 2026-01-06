#include <algorithm>
#include <climits>
#include <cmath>
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

int LISRec(vector<int>& arr) {
    int n = arr.size();
    function<int(int, int)> recruse = [&](int idx, int prev) -> int {
        if (idx == n) return 0;
        int take = 0;
        if (arr[idx] > prev) {
            take = 1 + recruse(idx + 1, arr[idx]);
        }
        int skip = recruse(idx + 1, prev);
        return max(take, skip);
    };
    return recruse(0, INT_MIN);
}

int LIS_TD_DP(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    function<int(int, int)> recruse = [&](int idx, int prevIdx) -> int {
        if (idx == n) return dp[idx][prevIdx + 1] = 0;
        if (dp[idx][prevIdx + 1] != -1) {
            return dp[idx][prevIdx + 1];
        }

        int take = 0;
        if (prevIdx == -1 || arr[idx] > arr[prevIdx]) {
            take = 1 + recruse(idx + 1, idx);
        }
        int skip = recruse(idx + 1, prevIdx);
        return dp[idx][prevIdx + 1] = max(take, skip);
    };
    return recruse(0, -1);
}

int LIS_BU_DP(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int LISOPT(vector<int>& arr){
    vector<int> tails;
    for(int x: arr){
        auto it = lower_bound(tails.begin(), tails.end(),x);
        if(it==tails.end()){
            tails.push_back(x);
        }else{
            *it =x;
        }
    }
    return tails.size();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    cout << LISOPT(arr) << endl;
    return 0;
}
