#include <cstdio>
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
        int n;
        cin >> n;
        vector<int> p(n + 1);

        p[n] = 1;
        for (int i = 2; i < n; i++) p[i] = i ^ 1;

        p[1] = (n % 2 == 0) ? n : n - 1;

        for (int i = 1; i <= n; i++) cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}
