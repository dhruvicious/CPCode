#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int                 left = 0, right = 0;
        int                 maxLen = 0;
        unordered_set<char> inString;
        while (right < s.size()) {
            if (inString.find(s[right]) != inString.end()) {
                inString.erase(s[left++]);
            } else {
                inString.insert(s[right++]);
                maxLen = max(maxLen, (right - left + 1));
            }
        }
        return maxLen;
    }
};
