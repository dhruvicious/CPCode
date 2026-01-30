#include <algorithm>
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
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int& i : arr) {
            cin >> i;
        }

        sort(arr.begin(), arr.end());

        int maxMX = 1;
        int currS = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1] + 1) {
                currS++;
            } else if (arr[i] == arr[i - 1]) {
                continue;
            } else {
                currS = 1;
            }
            maxMX = max(maxMX, currS);
        }

        cout << maxMX << endl;
    }
    return 0;
}
