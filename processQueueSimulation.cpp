#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    queue<int> callingOrder;
    queue<int> idealOrder;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        callingOrder.push(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        idealOrder.push(x);
    }

    int timeUnits = 0;
    while (!idealOrder.empty()) {
        if (callingOrder.front() == idealOrder.front()) {
            callingOrder.pop();
            idealOrder.pop();
            timeUnits++;
        } else {
            int temp = callingOrder.front();
            callingOrder.pop();
            callingOrder.push(temp);
            timeUnits++;
        }
    }

    cout << timeUnits << endl;

    return 0;
}