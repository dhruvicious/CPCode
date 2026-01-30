#include <cstdio>
#include <ios>
#include <iostream>

void fastIO() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
}

int main(int argCount, char* argsValue[]) {
    fastIO();
#ifndef ONLINE_JUDGE
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";
    if (argCount >= 3) {
        inputFile = argsValue[1];
        outputFile = argsValue[2];
    }
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}
