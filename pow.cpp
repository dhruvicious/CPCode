#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   public:
    double pow(double x, int n) {
        if (x == 0.0 && n <= 0) return NAN;

        long long N = n;
        double ans = 1.0;

        if (N < 0) {
            x=1/x;
            N=-N;
        }

        while(N>0){
            if(N%2==1){
                ans*=x;
            }
            x*=x;
            N/=2;
        }
        
        return ans;
    }
};

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}