#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        for (int& i : a) cin >> i;
        for (int& i : b) cin >> i;
        string s;
        cin >> s;

        vector<long long> D(k + 1);
        for (int i = 1; i <= k; i++) {
            D[i] = D[i - 1] + (s[i - 1] == 'R' ? 1 : -1);
        }
        unordered_map<long long, int> first;
        first.reserve(k * 2);

        for (int i = 0; i <= k; i++) {
            if (!first.count(D[i])) {
                first[D[i]] = i;
            }
        }

        vector<int> deathCount(k + 2, 0);
        for (long long ai : a) {
            int best = INT_MAX;
            for (long long bi : b) {
                long long need = bi - ai;
                if (first.count(need)) {
                    best = min(best, first[need]);
                }
            }
            if (best != INT_MAX && best > 0) {
                deathCount[best]++;
            }
        }
        int alive = n;
        for (int i = 1; i <= k; i++) {
            alive -= deathCount[i];
            cout << alive << ' ';
        }
        cout << endl;
    }
    return 0;
}
