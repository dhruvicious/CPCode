#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        bool allequal = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) {
                allequal = false;
                break;
            }
        }
        if (allequal) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        cout << a[n - 1] << " " << a[0] << ' ';
        for (int i = 1; i < n - 1; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
