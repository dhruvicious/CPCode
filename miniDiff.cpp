#include <iostream>
#include <vector>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;

        int first = arr[0];
        int last = arr[n - 1];
        int ans;
        if (first != -1 && last != -1) {
            ans = abs(first - last);
        } else if (first != -1 && last == -1) {
            ans = 0;
            arr[n - 1] = arr[0];
        } else if (first == -1 && last != -1) {
            ans = 0;
            arr[0] = arr[n - 1];
        } else {
            arr[0] = 0;
            arr[n - 1] = 0;
            ans = 0;
        }

        for (int& i : arr) {
            if (i == -1) {
                i = 0;
            }
        }

        cout << ans << '\n';
        for (int i : arr) cout << i << " ";
        cout << '\n';
    }
    return 0;
}