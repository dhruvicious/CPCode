#include <cstdio>
#include <ios>
#include <iostream>
#include <vector>

void fastIO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
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
        int n, s, x;
        std::cin >> n >> s >> x;
        std::vector<int> arr(n);
        int sum = 0;
        for (int& i : arr) {
            std::cin >> i;
            sum+=i;
        }

        if (sum <= s && ((s - sum) % x) == 0) {
            std::cout << "Yes\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
