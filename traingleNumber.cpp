#include <bits/stdc++.h>
using namespace std;

int recursiveSum(int n) {
    if (n == 0) return 0;
    return n + recursiveSum(n - 1);
}
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout<<recursiveSum(n);
    return 0;
}