#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void solve(vector<int> arr, int target, int index, vector<int>& ans) {
    if (index == arr.size()) return;
    if (arr[index] == target) ans.push_back(index);
    solve(arr, target, index + 1, ans);
}

int32_t main() {
    fastio
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& num : arr) cin >> num;
    int m;
    cin >> m;
    vector<int> ans;
    solve(arr, m, 0, ans);
    for (int index : ans) cout << index << " ";
    return 0;
}