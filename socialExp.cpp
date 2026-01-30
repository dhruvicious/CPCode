#include <iostream>

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
        if (n == 2) cout << 2 << endl;
        if (n == 3) cout << 3 << endl;
        if (n > 3 && n % 2 == 0) cout << 0 << endl;
        if (n > 3 && n % 2 != 0) cout << 1 << endl;
    }
    return 0;
}
