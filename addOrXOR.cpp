#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
const ll INF = (1LL<<60);


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int a,b;
        ll x,y;
        cin>>a>>b>>x>>y;
        int N=max(b,a)+105;
        vector<ll> dist(N, INF);
        using P =pair<ll, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        if(a<N){
            dist[a]=0;
            pq.emplace(0,a);
        }
        while(!pq.empty()){
            auto [d,u] =pq.top();
            pq.pop();
            if(d>dist[u]){
                continue;
            }
            if(u==b) break;
            if(u+1<N && dist[u+1]>d+x){
                dist[u+1]=d+x;
                pq.emplace(dist[u+1], u+1);
            }
            int v=u^1;
            if(v >= 0 && v < N && dist[v] > d + y){
                dist[v] = d + y;
                pq.emplace(dist[v], v);
            }
        }
        if(dist[b] >= INF) cout<<"-1\n"; 
        else cout<<dist[b]<<'\n';
    }
    return 0;
}