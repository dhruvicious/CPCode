#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int32_t main() {
    fastio
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        ll px, py, qx, qy;
        cin>>n>>px>>py>>qx>>qy;
        
        vector<ll> a(n);
        ll sum=0, maxa=0;
        
        for (int i=0;i<n;i++) {
            cin>>a[i];
            sum +=a[i];
            maxa =max(maxa, a[i]);
        }
        
        ll dx=qx-px,dy=qy-py;
        ll D2 =dx*dx + dy*dy;
        
        ll Lmin=max(0LL,maxa -(sum-maxa));
        ll L2 =Lmin*Lmin;
        ll S2 =sum*sum;
        
        ll D = (ll)sqrt(D2);
        bool is_perfect_square =(D*D==D2);
        
        bool reachable = is_perfect_square && (L2<=D2)&&(D2<=S2)&&((sum-D)%2==0);
        cout << (reachable ? "Yes" : "No") << endl;
    }
    
    return 0;
}