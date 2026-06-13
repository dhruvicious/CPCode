#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(4 * n + 1);

    for (int i = 1; i <= n; i++) {
        a[i]         = i;
        a[n + i]     = n - i + 1;
        a[2 * n + i] = n - i + 1;
        a[3 * n + i] = i;
    }

    if (n % 2 == 1) {
        int m = (n + 1) / 2;
        swap(a[n], a[2 * n - m + 1]);
    }

    for (int i = 1; i <= 4 * n; i++) {
        cout << a[i] << (i == 4 * n ? "" : " ");
    }
    cout << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
