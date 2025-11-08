#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<string> vec(n);
    for (string& s : vec) cin >> s;
    sort(vec.begin(), vec.end(), [](const string& a, const string& b) {
        if (b.find(a) == 0 || a.find(b) == 0) {
            return a.size() > b.size();
        }
        return a < b;
    });
    for (string& s : vec) cout << s << endl;
    return 0;
}