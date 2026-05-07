#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        int length = s.size();

        for (int rotCount = 0; rotCount < length; rotCount++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) return true;
        }
        return false;
    }
};

int main() {
    string s, goal;
    cin >> s >> goal;
    Solution sol;
    sol.rotateString(s, goal);
}
