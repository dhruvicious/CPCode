#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    unordered_map<int, int> freq;
    while (n--) {
        int x;
        cin >> x;
        freq[x]++;
    }
    vector<pair<int, int>> elements(freq.begin(), freq.end());
    sort(elements.begin(), elements.end(),
         [](auto& a, auto& b) { return a.second > b.second; });
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(elements[i].first);
    }
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}