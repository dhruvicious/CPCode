#include <bits/stdc++.h>
using namespace std;

void printOdd(int n) {
    if (n == 0) return;
    if (n % 2 != 0) cout << n << endl;
    printOdd(n - 1);
}

void printEven(int curr, int n) {
    if (curr > n) return;
    cout << curr << endl;
    printEven(curr+2, n);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    printOdd(n);
    printEven(2, n);
    return 0;
}