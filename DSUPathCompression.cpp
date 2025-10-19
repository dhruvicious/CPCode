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
        rank = new int[N+1];
        for (int i = 0; i <= N; i++) {
            // Initially everyone is a parent of itself
            parent[i] = i;
            rank[i]=1;
        }
    }

    int getLeader(int u) {
        // Will fetch the leader of a Set
        if (u == parent[u]) return u;
        return parent[u]=getLeader(parent[u]);
    }
    void unionLeader(int u, int v) {
        int leaderU = getLeader(u);
        int leaderV = getLeader(v);
        if (leaderU != leaderV) {
            if(rank[leaderU]<rank[leaderV]){
                swap(leaderU, leaderV);
            }

            parent[leaderV]= leaderU;
            if(rank[leaderU]==rank[leaderV]){
                rank[leaderU]++;
            }
        }
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}