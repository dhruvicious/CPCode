#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int gc;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (i == 0)
                gc = val;
            else
                gc = gcd(gc, val);
        }
        int ans = -1;
        for (int p : primes) {
            if (gc % p != 0) {
                ans = p;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}