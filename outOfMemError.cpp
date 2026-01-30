#include <cstdio>
#include <iostream>
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
        int n, m;
        long long h;
        cin >> n >> m >> h;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        const vector<int> arrCPY = arr;
        vector<int> hist;
        while (m--) {
            int b;
            long long c;
            cin >> b >> c;
            int idx = b - 1;
            long long val = arr[idx] + c;
            if (val > h) {
                for (int modIdx : hist) {
                    arr[modIdx] = arrCPY[modIdx];
                }
                hist.clear();
            } else {
                arr[idx] = val;
                hist.push_back(idx);
            }
        }
        for (int i : arr) cout << i << " ";
        cout << endl;
    }
    return 0;
}
