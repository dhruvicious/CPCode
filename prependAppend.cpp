#include <cstdio>
#include <iostream>
#include <string>
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
        string s;
        cin >> s;

        int l = 0, r = n - 1;
        while (l < r && s[l] != s[r]) {
            l++;
            r--;
        }
        if (l > r) {
            cout << n % 2 << endl;
        } else {
            cout << (r - l + 1) << endl;
        }
    }
    return 0;
}
