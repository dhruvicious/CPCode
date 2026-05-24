#include <algorithm>
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
            i %= 2;
        }
        int ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            ans += (!(arr[i] ^ arr[i + 1]));
        }
        cout << ans << '\n';
    }
    return 0;
}
