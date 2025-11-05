#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (vector<int>& vec : arr) {
        for (int& i : vec) {
            cin >> i;
        }
    }
    queue<int> q;
    for (vector<int>& vec : arr) {
        for (int& i : vec) {
            q.push(i);
        }
    }
    int r, c;
    cin >> r >> c;
    if ((r * c) != (m * n)) {
        for (vector<int>& vec : arr) {
            for (int i : vec) {
                cout << i << " ";
            }
            cout << endl;
        }
    } else {
        vector<vector<int>> repArr(r, vector<int>(c));
        for (vector<int>& vec : repArr) {
            for (int& i : vec) {
                i = q.front();
                q.pop();
            }
        }

        for (vector<int> vec : repArr) {
            for (int i : vec) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}