#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void fastIO() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
}

class Solution {
   public:
    int minCost(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<std::pair<int, int>>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, 2 * w);
        }
        std::vector<int> d(n, INT_MAX);
        std::vector<bool> v(n, false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        d[0] = 0;
        q.emplace(0, 0);

        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (x == n - 1) {
                return d[x];
            }
            if (v[x]) continue;
            v[x] = 1;
            for (auto& [y, w] : g[x]) {
                if (d[x] + w < d[y]) {
                    d[y] = d[x] + w;
                    q.emplace(d[y], y);
                }
            }
        }
        return -1;
    }
};

int main() {
    fastIO();
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> arr(n, std::vector<int>(3, 0));
        for (std::vector<int>& vec : arr) {
            for (int& i : vec) std::cin >> i;
        }
    }
}
