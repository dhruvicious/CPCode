#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int oddcount = 0;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val % 2 != 0) {
                oddcount++;
            }
        }
        if (oddcount % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
