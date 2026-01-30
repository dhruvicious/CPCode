#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
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
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        vector<pair<int, int>> cards(n);
        for (int i = 0; i < n; i++) {
            cards[i].first = arr[i];
            cards[i].second = i;
        }
        sort(cards.begin(), cards.end());
        bool possible = true;
        for (int i = 0; i < n - 1; i++) {
            int idx = cards[i].second;
            int idx2 = cards[i + 1].second;
            if (abs(idx - idx2) % 2 == 0) {
                possible = false;
                break;
            }
        }
        cout << ((possible) ? "Yes\n" : "No\n");
    }
    return 0;
}
