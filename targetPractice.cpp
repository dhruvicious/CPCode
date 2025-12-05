#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> target = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1}, {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1}, {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1}, {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    int t;
    cin >> t;
    while (t--) {
        vector<vector<char>> hits(10, vector<char>(10));
        for (vector<char>& vec : hits) {
            for (char& c : vec) {
                cin >> c;
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (hits[i][j] == 'X') {
                    ans += target[i][j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}