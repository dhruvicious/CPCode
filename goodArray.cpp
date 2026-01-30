#include <algorithm>
#include <iostream>
#include <vector>

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
        vector<long long> a(n);
        for (long long& i : a) cin >> i;

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        
        long long ops =0;
    }
    return 0;
}
