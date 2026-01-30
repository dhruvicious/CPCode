#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void IO(int argsC, char* argsV[]) {
    const char* inputFile = argsC >= 3 ? argsV[1] : "input.txt";
    const char* outputFile = argsC >= 3 ? argsV[2] : "output.txt";
#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

int main(int argsC, char* argsV[]) {
    fastIO();
    IO(argsC, argsV);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int l = 1, r = n;
        vector<int> arr(n);

        for (int i = n - 1; i >= 0; i--) {
            if ((n - 1 - i) % 2 == 0) {
                arr[i] = r;
                r--;
            } else {
                arr[i] = l;
                l++;
            }
        }
        for (int& i : arr) cout << i << " ";
        cout << '\n';
    }
}
