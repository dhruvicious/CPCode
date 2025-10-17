#include <bits/stdc++.h>
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int q;
    cin >> q;

    queue<int> mainQueue;
    queue<int> courseQueue[5];
    bool inQueue[5] = {false};

    while (q--) {
        string op;
        cin >> op;

        if (op == "E") {
            int x, y;
            cin >> x >> y;
            courseQueue[x].push(y);
            if (!inQueue[x]) {
                mainQueue.push(x);
                inQueue[x] = true;
            }
        } else if (op == "D") {
            int course = mainQueue.front();
            int roll = courseQueue[course].front();
            cout << course << " " << roll << "\n";
            courseQueue[course].pop();
            if (courseQueue[course].empty()) {
                mainQueue.pop();
                inQueue[course] = false;
            }
        }
    }
    return 0;
}