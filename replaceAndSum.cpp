#include <algorithm>
#include <cstdio>
#include <ios>
#include <iostream>
#include <vector>

void fastIO() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
}

int main() {
    fastIO();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        int n, q;
        std::cin >> n >> q;
        std::vector<int> a(n);
        std::vector<int> b(n);
        for (int& i : a) std::cin >> i;
        for (int& i : b) std::cin >> i;
        std::vector<long long> suffMax(n + 2, 0);
        for (int i = n; i >= 1; i--) {
            long long currSource = std::max(a[i - 1], b[i - 1]);
            suffMax[i] = std::max(suffMax[i + 1], currSource);
        }
        std::vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + suffMax[i];
        }
        while (q--) {
            int l, r;
            std::cin >> l >> r;
            long long ans = pref[r] - pref[l - 1];
            std::cout << ans << " ";
        }
        std::cout << std::endl;
    }
}
