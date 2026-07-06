#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> letterCaseCombination(string s) {
        vector<string>      res;
        function<void(int)> backtrack = [&](int i) -> void {
            if (i == s.size()) {
                res.push_back(s);
                return;
            }
            backtrack(i + 1);
            if (isalpha(s[i])) {
                s[i] ^= 0x20;
                backtrack(i + 1);
                s[i] ^= 0x20;
            }
        };
        backtrack(0);
        return res;
    }
};

int main() {
}
