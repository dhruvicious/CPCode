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
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::vector<int> b(n);
        for (int& i : a) std::cin >> i;
        for (int& i : b) std::cin >> i;
        
    }
}
