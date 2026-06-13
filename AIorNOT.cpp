#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, x, y, z;
        cin >> n >> x >> y >> z;

        long long firstVal = ceil_div(n, x + y);

        long long secondVal;
        if (z * x >= n) {
            secondVal = ceil_div(n, x);
        } else {
            long long remainTime = n - (z * x);
            secondVal            = z + ceil_div(remainTime, x + 10 * y);
        }

        cout << min(firstVal, secondVal) << '\n';
    }

    return 0;
}
