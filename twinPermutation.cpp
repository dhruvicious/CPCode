#include <iostream>

using namespace std;

typedef long long ll;

void tc() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << n + 1 - x << " ";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) tc();
    return 0;
}
