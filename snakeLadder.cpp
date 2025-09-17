#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

long long countWays(int pos, int n2, int m){
    if(pos==n2) return 1;
    if(pos>n2) return 0;

    long long ways=0;
    for(int i=1;i<=m;i++){
        ways+= countWays(pos+i, n2, m);
    }

    return ways;
}

void printways(int pos, int N2, int m, vector<int> path){
    if(pos==N2){
        for(int v: path) cout<<v;
        cout<<" ";
        return;
    }
    if(pos>N2) return;
    for(int dice=1;dice<=m;dice++){
        path.push_back(dice);
        printways(pos+dice, N2, m, path);
        path.pop_back();
    }
}

int32_t main() {
    fastio
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n,m;
    cin>>n>>m;
    vector<int> path;
    printways(0, n, m, path);
    cout<<endl;
    cout<<countWays(0, n, m);
    
    return 0;
}