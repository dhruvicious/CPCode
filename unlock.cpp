#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    int k;
    cin >> n >> k;

    vector<int> arr(n);
    unordered_map<int, int> posMap;
    priority_queue<int> pq;

    for (int& i : arr) cin >> i;
    for (int i = 0; i < n; i++) posMap[arr[i]] = i;
    for (int& i : arr) pq.push(i);

    for (int i = 0; i < n && k > 0; i++) {
        while (!pq.empty() && posMap[pq.top()] < i) {
            pq.pop();
        }
        if (pq.empty()) break;

        int largest = pq.top();

        if (arr[i] == largest) continue;

        int idx = posMap[largest];

        swap(arr[i], arr[idx]);
        posMap[arr[idx]] = idx;
        posMap[arr[i]] = i;

        k--;
    }

    return 0;
}