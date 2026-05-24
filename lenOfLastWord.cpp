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
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == ' ') i--;
        int len = 0;

        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        return len;
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
