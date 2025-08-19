#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int minimumTime(vector<vector<int>>& moveTime){
            int n = moveTime.size();
        int m = moveTime[0].size();
        
        using ll = long long;
        const ll INF = LLONG_MAX / 4;

        
        vector<vector<ll>> dist(n, vector<ll>(m, INF));
        dist[0][0] = 0;

        
        using State = tuple<ll,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.emplace(0, 0, 0);

        
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            
            if (t > dist[i][j]) 
                continue;

            
            if (i == n-1 && j == m-1) 
                return int(t);

            
            for (auto &d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) 
                    continue;

                
                ll start   = max(t, ll(moveTime[ni][nj]));
                ll arrival = start + 1;
                if (arrival < dist[ni][nj]) {
                    dist[ni][nj] = arrival;
                    pq.emplace(arrival, ni, nj);
                }
            }
        }

        
        return -1;
        }
};

int main() {
    
    return 0;
}