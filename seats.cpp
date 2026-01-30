#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void IO(int argsC, char* argsV[]) {
    const char* inputFile = (argsC >= 3) ? argsV[1] : "input.txt";
    const char* outputFile = (argsC >= 3) ? argsV[2] : "output.txt";

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
        string s;
        cin >> s;

        vector<int> occIdx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') occIdx.push_back(i);
        }
        if (occIdx.empty()) {
            cout << (n + 2) / 3 << '\n';
            continue;
        }

        int addStd = 0;

        addStd += (occIdx[0] + 1) / 3;
        addStd += (n - occIdx.back()) / 3;

        for (size_t i = 0; i < occIdx.size()-1; i++) {
            addStd += (occIdx[i + 1] - occIdx[i] - 1) / 3;
        }

        cout << occIdx.size() + addStd << '\n';
    }
}
