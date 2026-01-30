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
    const char* inpFile = (argsC >= 3) ? argsV[1] : "input.txt";
    const char* outFile = (argsC >= 3) ? argsV[2] : "output.txt";
#ifndef ONLINE_JUDGE
    freopen(inpFile, "r", stdin);
    freopen(outFile, "w", stdout);
#endif
}

int main(int argsC, char* argsV[]) {
    fastIO();
    IO(argsC, argsV);

    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        
        vector<string> original;
        vector<string> changed;
        vector<int> cost;
        
        
    }
}
