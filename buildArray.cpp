#include <bits/stdc++.h>
using namespace std;

#define forin for(int i =0;i<n;i++)

void solve(){
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long totalLeaves = 0;
        forin {
            long long x;
            cin >> x;
            if (totalLeaves < k) {
                int twos = __builtin_ctzll(x);
                long long leaves = (1LL << twos);
                totalLeaves += leaves;
                if (totalLeaves > k) {
                    totalLeaves = k;
                }
            }   
        }
        if (k >= n && k <= totalLeaves) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}


int main() {
    solve();
    return 0;
}