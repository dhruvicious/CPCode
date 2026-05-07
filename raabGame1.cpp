#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void FileIO(char* inputFile, char* outputFile) {
#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

void solve(int n, int a, int b) {
    int d = n - a - b;
    if (!((a == 0 && b == 0) || (a > 0 && b > 0 && a + b <= n))) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    vector<int> p1, p2;

    for (int i = 0; i < a; i++) {
        p1.push_back(n - i);
        p2.push_back(d + 1 + i);
    }

    for (int i = 0; i < b; i++) {
        p2.push_back(n - a - i);
        p1.push_back(d + a + 1 + i);
    }

    for (int i = 0; i < d; i++) {
        p1.push_back(i + 1);
        p2.push_back(i + 1);
    }

    for (int x : p1) cout << x << " ";
    cout << '\n';
    for (int x : p2) cout << x << " ";
    cout << '\n';

    cout << endl;
}

// argsV[0] -> executable name
// argsV[1] -> input file
// argsV[2] -> output file
int main(int argC, char* argsV[]) {
    fastIO();

    if (argC >= 3) {
        FileIO(argsV[1], argsV[2]);
    }

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }
    return 0;
}
