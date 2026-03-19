#include <iostream>
#include <vector>

using namespace std;

int oddCount(int x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    return x;
}

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
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        bool possible = true;
        for (int i = 1; i <= n; i++) {
            if (oddCount(i) != oddCount(arr[i])) {
                possible = false;
                break;
            }
        }
        cout << (possible ? "Yes\n" : "No\n");
    }
    return 0;
}
