#include <bits/stdc++.h>
using namespace std;

class DSU {
   public:
    int* parent;
    int n;
    int* rank;
    DSU(int N) {
        n = N;
        parent = new int[N + 1];
        rank = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            // Initially everyone is a parent of itself
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int getLeader(int u) {
        // Will fetch the leader of a Set
        if (u == parent[u]) return u;
        return parent[u] = getLeader(parent[u]);
    }
    void unionLeader(int u, int v) {
        int leaderU = getLeader(u);
        int leaderV = getLeader(v);
        if (leaderU != leaderV) {
            if (rank[leaderU] < rank[leaderV]) {
                swap(leaderU, leaderV);
            }

            parent[leaderV] = leaderU;
            if (rank[leaderU] == rank[leaderV]) {
                rank[leaderU]++;
            }
        }
    }
};

class Tuple {
   public:
    char u, v;
    int dist;

    static bool comp(const Tuple& a, const Tuple& b) { return a.dist < b.dist; }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<Tuple> edges;

    edges.push_back({1, 2, 1});
    edges.push_back({1, 3, 2});
    edges.push_back({2, 4, 8});
    edges.push_back({3, 4, 3});
    edges.push_back({3, 5, 5});
    edges.push_back({5, 4, 4});
    int minWeight = 0;
    DSU d(5);

    sort(edges.begin(), edges.end());
    for (auto t : edges) {
        int u = t.u;
        int v = t.v;

        int dist = t.dist;

        int leaderU = d.getLeader(u);
        int leaderV = d.getLeader(v);

        if (leaderU != leaderV) {
            d.unionLeader(leaderU, leaderV);
            minWeight += dist;
        }
    }

    return 0;
}