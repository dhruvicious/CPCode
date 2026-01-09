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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<bool> pre(n + 2, false);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] < n + 2) {
                pre[arr[i]] = true;
            }
        }
        int initMex = 0;
        while (pre[initMex]) {
            initMex++;
        }
        cout << min(k - 1, initMex) << endl;
    }
    return 0;
}
