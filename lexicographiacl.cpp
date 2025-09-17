#include <bits/stdc++.h>
using namespace std;

void lexicographcial(int curr, int n) {
    if (curr > n) return;
    cout << curr << " ";
    for (int i = 0; i <= 9; i++) {
        if (curr == 0 && i == 0) continue;
        int next = curr * 10 + i;
        if (next > n) return;
        lexicographcial(next, n);
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    lexicographcial(0, n);
    return 0;
}