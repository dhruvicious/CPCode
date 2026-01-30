#include <algorithm>
#include <cstdio>
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
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int& i : arr) std::cin >> i;
        std::vector<int> suffMax(n);
        suffMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMax[i] = std::max(suffMax[i + 1], arr[i]);
        }

        bool reversed = false;
        for (int i = 0; i < n && !reversed; i++) {
            if (arr[i] == suffMax[i]) {
                continue;
            }

            int j = n - 1;
            while (arr[j] != suffMax[i]) {
                j--;
            }
            std::reverse(arr.begin() + i, arr.begin() + j + 1);
            reversed = true;
        }

        for (int i : arr) std::cout << i << " ";
        std::cout << "\n";
    }
}
