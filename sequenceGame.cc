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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;

        vector<int> ans;
        ans.push_back(arr[0]);
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                ans.push_back(arr[i]);
            } else {
                ans.push_back(arr[i]);
                ans.push_back(arr[i]);
            }
        }
        cout << ans.size() << endl;
        for (int i : ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}
