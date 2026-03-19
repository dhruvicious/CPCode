#include <cstdio>
#include <iostream>

using namespace std;

long long digitCount(int n) {
    long long s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n % 9 != 0) {
            cout << 0 << endl;
            continue;
        }

        int count = 0;
        for (long long y = n; y < n + 90; y++) {
            if (y - digitCount(y) == n) {
                count++;
            }
        }
        cout << count << endl;
    }
}
