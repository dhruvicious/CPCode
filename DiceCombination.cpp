#include <cstdio>
#include <iostream>

using namespace std;

int MOD = 1e9 + 7;

int solve(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    long long ways = 0;
    for (int diceVal = 1; diceVal <= 6; diceVal++) {
        ways = (ways + solve(n - diceVal)) % MOD;
    }
    return ways;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n = 0;
    cin >> n;
    cout << solve(n);
}
