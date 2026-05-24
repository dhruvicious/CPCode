#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdio.h>

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

class Solution {
   public:
    bool isPalindrome(string s) {
        string norm;
        for (char c : s) {
            if (isalpha(c)) {
                if ('a' < c && c < 'z') {
                    norm.push_back(c);
                } else {
                    norm.push_back(c ^ 0x20);
                }
            }
        }
        string normCpy = norm;
        reverse(norm.begin(), norm.end());
        if (normCpy == norm) {
            return true;
        } else {
            return false;
        }
    }
};

// argsV[0] -> executable name
// argsV[1] -> input file
// argsV[2] -> output file
int main(int argC, char* argsV[]) {
    fastIO();

    if (argC >= 3) {
        FileIO(argsV[1], argsV[2]);
    }

    return 0;
}
