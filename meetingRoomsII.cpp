#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<pair<int, int>> intervals = {
        {0, 5}, {2, 6}, {3, 4}, {7, 9}, {8, 11}};

    sort(intervals.begin(), intervals.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.first < b.first;
         });

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto& p : intervals) {
        int st = p.first;
        int et = p.second;

        if (pq.empty()) {
            pq.push(et);
        } else {
            if (st >= pq.top()) {
                pq.pop();
            }
            pq.push(et);
        }
    }

    cout << pq.size();
    return 0;
}