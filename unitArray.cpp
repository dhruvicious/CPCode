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
        int NegOneCount = 0;
        int PosiOneCount = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == -1)
                NegOneCount++;
            else if (x == 1)
                PosiOneCount++;
        }
        int S = PosiOneCount - NegOneCount;
        int operations = 0;

        if (S < 0) {
            int flipsForSum = (-S + 1) / 2;
            operations += flipsForSum;
            NegOneCount -= flipsForSum;
        }
        if (NegOneCount % 2 != 0) {
            operations++;
        }

        cout << operations << endl;
    }
    return 0;
}
