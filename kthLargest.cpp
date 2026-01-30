#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : arr) {
        pq.push(x);
        if (pq.size() > k) pq.pop();
    }
    cout << pq.top() << endl;
    return 0;
}
