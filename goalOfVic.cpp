#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif       
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int eff;
        int ans = 0;
        while (n--) {
            cin >> eff;
            ans += eff;
        }
        cout << -(ans) << endl;
    }
    return 0;
}