#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);

    int current_n = n;

    while (current_n > 0) {
        int msb_pos = 0;
        if (current_n > 0) {
            msb_pos = 31 - __builtin_clz(current_n);
        }
        int L = 1 << msb_pos;
        
        int target = 2 * L - 1;

        if (target > current_n) {
            cout << -1 << "\n";
            return;
        }

        int start_y = L;
        int end_y = current_n;

        for (int y = start_y; y <= end_y; ++y) {
            int x = target - y;
            swap(p[x], p[y]);
        }
        current_n = target - current_n - 1;
    }

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


