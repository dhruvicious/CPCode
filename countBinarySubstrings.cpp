#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int countBinarySubstrings(string s) {
        int prevGroup = 0, currGroup = 1;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                currGroup++;
            else {
                res += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }

        res += min(currGroup, prevGroup);

        return res;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    sol.countBinarySubstrings(s);
}
