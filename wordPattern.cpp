#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        stringstream   ss(s);
        vector<string> words;
        string         word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) return false;

        unordered_map<string, char> mapWP;
        unordered_map<char, string> mapPW;

        for (int i = 0; i < pattern.size(); i++) {
            char   c = pattern[i];
            string w = words[i];

            if (mapWP.count(w)) {
                if (mapWP[w] != c) return false;
            } else {
                mapWP[w] = c;
            }
            if (mapPW.count(c)) {
                if (mapPW[c] != w) return false;
            } else {
                mapPW[c] = w;
            }
        }
        return true;
    }
};

int main() {
}
