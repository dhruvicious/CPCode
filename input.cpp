#include <cstdio>
#include <iostream>

const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cerr.tie(nullptr);
    return 0;
}();

#define endl "\n"


void termIO(char* inputFile, char* outputFile, char* errFile) {
#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
    freopen(errFile, "w", stderr);
#endif
}

void solve() {
}

int main(int argsC, char* argsV[]) {
    if (argsC >= 4) {
        termIO(argsV[1], argsV[2], argsV[3]);
    } else {
        termIO((char*) "input.txt", (char*) "output.txt", (char*) "error.txt");
    }

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
