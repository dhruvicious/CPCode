#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int room) -> void {
            visited[room] = true;
            for (int key : visited) {
                if (!visited[key]) {
                    dfs(key);
                }
            }
        };
        dfs(0);

        for (bool b : visited) {
            if (!b) return false;
        }
        return true;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
