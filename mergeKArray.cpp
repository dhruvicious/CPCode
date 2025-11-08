#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    int k;
    cin >> k >> n;
    map<int, int> freq;
    for (int i = 0; i < k * n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    for (auto& p : freq) {
        while (p.second--) cout << p.first << " ";
    }
    return 0;
}