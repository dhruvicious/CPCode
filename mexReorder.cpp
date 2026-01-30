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
        int count1 = 0, count0 = 0;
        for (int& i : arr) {
            cin >> i;
            if (i == 0) count0++;
            if (i == 1) count1++;
        }

        if (count0 == 0) {
            cout << "NO\n";
            continue;
        }
        if (count0 > 1 && count1 == 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}
