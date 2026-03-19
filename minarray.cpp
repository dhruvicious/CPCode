#include <algorithm>
#include <cmath>
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

int minArrayLen(vector<int> arr) {
    int len = arr.size();
    int b1 = -1, b2 = -1;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (arr[j] < arr[i]) {
                b1 = i;
                break;
            }
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (arr[j] > arr[i]) {
                b2 = i;
                break;
            }
        }
    }
    if (b1 == -1) return 0;
    return b2 - b1 + 1;
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
