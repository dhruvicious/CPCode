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
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                cout << 1 << " ";
            }
            cout << "\n";
        }
        else {
            if (k == 1) {
                cout << "NO\n";
            } else if (k == 2) {
                if (n % 2 != 0) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    cout << n / 2 << "\n";
                    for (int i = 0; i < n / 2; i++) {
                        cout << 2 << " ";
                    }
                    cout << "\n";
                }
            } else { 
                if (n == 1) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    if (n % 2 == 0) {
                        cout << n / 2 << "\n";
                        for (int i = 0; i < n / 2; i++) {
                            cout << 2 << " ";
                        }
                    } else {
                        cout << (n - 3) / 2 + 1 << "\n";
                        cout << 3 << " ";
                        for (int i = 0; i < (n - 3) / 2; i++) {
                            cout << 2 << " ";
                        }
                    }
                    cout << "\n";
                }
            }
        }
    }
    return 0;
}
