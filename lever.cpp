#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        
        int dec = 0, inc = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) dec += a[i] - b[i];
            else inc += b[i] - a[i];
        }
        
        cout << max(dec, inc) << "\n";
    }
}