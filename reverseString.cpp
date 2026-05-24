#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
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

class Solution {
   public:
    string reverseWords(string s) {
        int read  = 0;
        int write = 0;

        int            n = s.size();
        vector<string> res;

        while (read < n && s[read] == ' ') read++;
        while (read < n) {
            if (s[read] != ' ') {
                s[write++] = s[read++];
            } else {
                s[write++] = ' ';
                while (read < n && s[read] == ' ') read++;
            }
        }
        if (write > 0 && s[write - 1] == ' ') write--;
        s.resize(write);
        int start = 0;
        for (int end = 0; end < s.length(); end++) {
            if (end == s.length() || s[end] == ' ') {
                res.push_back(string(s.begin() + start, s.begin() + end));
                start = end + 1;
            }
        }
        return res[res.size() - 1];
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
