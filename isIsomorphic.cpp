#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapST, mapTS;

        for (int i = 0; i < s.size(); i++) {
            char cs = s[i], ct = t[i];
            if (mapST.count(cs)) {
                if (mapST[cs] != ct) return false;
            } else {
                mapST[cs] = ct;
            }
            if (mapTS.count(ct)) {
                if (mapTS[ct] != cs) return false;
            } else {
                mapTS[ct] = cs;
            }
        }
        return true;
    }
};

int main() {
}
