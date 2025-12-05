#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (long long& i : a) cin >> i;
        for (long long& i : b) cin >> i;

        long long maxK = 0;
        long long minK = 0;

        for (int i = 0; i < n; i++) {
            long long redMax = maxK - a[i];
            long long redMin = minK - a[i];
            long long blueMax = b[i] - minK;
            long long blueMin = b[i] - maxK;

            maxK = max(redMax, blueMax);
            minK = min(redMin, blueMin);
        }
        cout << maxK << endl;
    }
    return 0;
}
