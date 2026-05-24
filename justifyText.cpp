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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int            i = 0;

        while (i < words.size()) {
            int lineLength = words[i].size();
            int j          = i + 1;

            while (j < words.size()
                   && lineLength + 1 + words[j].size() <= maxWidth) {
                lineLength += 1 + words[j].size();
                j++;
            }

            int    gaps = j - i - 1;
            string line;

            if (j == words.size() || gaps == 0) {
                line = words[i];

                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }

                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalChars = 0;
                for (int k = i; k < j; k++) {
                    totalChars += words[k].size();
                }

                int totalSpaces = maxWidth - totalChars;

                int evenSpaces  = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];

                    int spaces = evenSpaces;
                    if (k - i < extraSpaces) {
                        spaces++;
                    }

                    line += string(spaces, ' ');
                }

                line += words[j - 1];
            }

            result.push_back(line);
            i = j;
        }

        return result;
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
