#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void printSubsets(vector<int>& arr, int idx, int target, vector<int>& curr) {
    if (idx == arr.size()) {
        if (target == 0) {
            for (int num : curr) cout << num << " ";
            cout << " ";
        }
        return;
    }

    curr.push_back(arr[idx]);
    printSubsets(arr, idx + 1, target - arr[idx], curr);

    curr.pop_back();
    printSubsets(arr, idx + 1, target, curr);
}

int countSubsets(vector<int>& arr, int idx, int target) {
    if (idx == arr.size()) {
        return (target == 0) ? 1 : 0;
    }
    return countSubsets(arr, idx + 1, target - arr[idx]) +
           countSubsets(arr, idx + 1, target);
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;

    vector<int> curr;
    printSubsets(arr, 0, target, curr);
    cout << '\n';

    cout << countSubsets(arr, 0, target) << '\n';
    return 0;
}