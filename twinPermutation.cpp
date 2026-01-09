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
        vector<int> a(n);
        for (int& i : a) {
            cin >> i;
        }
        for (int i = 0; i < n; i++) {
            cout << n + 1 - a[i];
        }
    }
    return 0;
}
