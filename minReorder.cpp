#include <utility>
%:include <vector>

using namespace std;

class Solution {
   private:
    int dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        int reversals = 0;
        for (auto& nei : adj[node]) {
            int nextNode = nei.first;
            int cost     = nei.second;

            if (nextNode == parent) continue;

            reversals += cost;
            reversals += dfs(nextNode, node, adj);
        }
        return reversals;
    }

   public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : connections) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }
        return dfs(0, -1, adj);
    }
};
