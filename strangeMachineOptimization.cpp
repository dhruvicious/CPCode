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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector<int> queries(q);
        for (int& qu : queries) cin >> qu;

        vector<int> result;
        result.reserve(q);
        bool allA = true;
        for (char c : s) {
            if (c == 'B') {
                allA = false;
            }
        }

        for (int qu : queries) {
            if (allA) {
                cout << qu << endl;
                continue;
            }
            int secs = 0;
            int i = 0;
            while (qu > 0) {
                if (s[i] == 'A')
                    qu--;
                else
                    qu >>= 1;
                secs++;
                i++;
                if (i == n) i = 0;
            }
            result.push_back(secs);
        }
        for (auto res : result) cout << res << '\n';
    }
    return 0;
}