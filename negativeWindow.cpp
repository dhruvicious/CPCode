#include <bits/stdc++.h>
using namespace std;

bool canAllocateCandies(vector<int>& candies, int k, int mid) {
    int maxNumChild = 0;
    for (int piles : candies) {
        maxNumChild += piles / mid;
    }
    return maxNumChild >= k;
}

int maxcandies(vector<int>& candies, int k) {
    int maxCandiesPile = 0;

    for (int i : candies) maxCandiesPile = max(maxCandiesPile, i);
    int left = 1;
    int right = maxCandiesPile;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canAllocateCandies(candies, k, mid)) {
            ans = mid;
            left = mid+1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    int k;
    cin >> k;
    int ans = maxcandies(arr, k);
    cout << ans;
    return 0;
}