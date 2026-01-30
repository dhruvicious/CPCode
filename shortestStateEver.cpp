#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void IO(int argC, char* argsV[]) {
    const char* IF = (argC >= 3) ? argsV[1] : "input.txt";
    const char* OF = (argC >= 3) ? argsV[2] : "output.txt";

#ifndef ONLINE_JUDGE
    freopen(IF, "r", stdin);
    freopen(OF, "w", stdout);
#endif
}

int main(int argsC, char* argsV[]) {
    fastIO();
    IO(argsC, argsV);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        int conflictBit = x & y;
        int msb = -1;
        for (int i = 29; i >= 0; i--) {
            if ((conflictBit >> i) & 1) {
                msb = i;
                break;
            }
        }

        if (msb == -1) {
            cout << x << ' ' << y << '\n';
            continue;
        }

        auto getCandi = [&](bool prioX) -> pair<int, int> {
            int p = 0, q = 0;
            for (int i = 29; i >= 0; i--) {
                if (i > msb) {
                    if ((x >> i) & 1) p |= (1 << i);
                    if ((y >> i) & 1) q |= (1 << i);
                } else if (i == msb) {
                    if (prioX)
                        p |= (1 << i);
                    else
                        q |= (1 << i);
                } else {
                    if (prioX) {
                        if ((x >> i) & 1) {
                            p |= (1 << i);
                        } else {
                            q |= (1 << i);
                        }
                    } else {
                        if ((y >> i) & 1) {
                            q |= (1 << i);
                        } else {
                            p |= (1 << i);
                        }
                    }
                }
            }
            return {p, q};
        };

        pair<int, int> cand1 = getCandi(true);
        pair<int, int> cand2 = getCandi(false);

        long long cost1 = (long long) abs(x - cand1.first) + abs(y - cand1.second);
        long long cost2 = (long long) abs(x - cand2.first) + abs(y - cand2.second);

        if (cost1 < cost2) {
            cout << cand1.first << ' ' << cand1.second << '\n';
        } else {
            cout << cand2.first << ' ' << cand2.second << '\n';
        }
    }
    return 0;
}
