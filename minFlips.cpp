#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int minFlips(int a, int b, int c){
    int flips=0;
    for(int i=0;i<32;i++){
        int bitA=(a>>i)&1;
        int bitB=(b>>i)&1;
        int bitC=(c>>i)&1;
        if(bitC==1){
            if(bitA==0&&bitB==0) flips++;
        }else{
            if(bitA==1) flips++;
            if(bitB==1) flips++;
        }
    }
    return flips;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}