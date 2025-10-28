#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> players;
        players.reserve(n);

        for (int i = 1; i <= n; i++) {
            players.push_back({gcd(n, i), i});
        }

        sort(players.begin(), players.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.first != b.first) {
                     return a.first > b.first;
                 }
                 return a.second < b.second;
             });
        for (auto& player : players) {
            cout << player.second << " ";
        }
        cout << endl;
    }
}