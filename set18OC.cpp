#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    set<pair<int, string>> s;
    s.insert({7, "D"});
    s.insert({5, "C"});
    s.insert({2, "B"});
    s.insert({2, "B"});

    while (!s.empty()) {
        auto address = s.begin();
        pair<int, string> p = *address;
        s.erase(address);
        cout << p.first << p.second;
    }
    return 0;
}