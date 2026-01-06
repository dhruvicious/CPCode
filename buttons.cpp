#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Lets code Bitch

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b) {
            cout << "FIRST" << endl;
        } else if (a < b) {
            cout << "SECOND" << endl;
        } else {
            if (c % 2 == 1) {
                cout << "FIRST" << endl;
            } else {
                cout << "SECOND" << endl;
            }
        }
    }
    return 0;
}
