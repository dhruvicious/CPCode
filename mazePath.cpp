#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

int countPaths(int r, int c, int N1, int N2) {
    if (r == N1 - 1 && c == N2 - 1) return 1;
    if (r >= N1 || c >= N2) return 0;

    int ways = 0;
    ways += countPaths(r + 1, c, N1, N2);
    ways += countPaths(r, c + 1, N1, N2);
    ways += countPaths(r + 1, c + 1, N1, N2);

    return ways;
}

void printPaths(int r, int c, int N1, int N2, string& currPath) {
    if (r == N1 - 1 && c == N2 - 1) {
        for (char path : currPath) cout << path;
        cout << " ";
        return;
    }
    if (r >= N1 || c >= N2) return;

    currPath.push_back('V');
    printPaths(r + 1, c, N1, N2, currPath);
    currPath.pop_back();
    
    currPath.push_back('H');
    printPaths(r, c + 1, N1, N2, currPath);
    currPath.pop_back();

    currPath.push_back('D');
    printPaths(r + 1, c + 1, N1, N2, currPath);
    currPath.pop_back();
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N1, N2;
    cin >> N1 >> N2;

    string currPath = "";

    printPaths(0, 0, N1, N2, currPath);
    cout << '\n' << countPaths(0, 0, N1, N2);
    return 0;
}