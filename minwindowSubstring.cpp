#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> targetCount(128, 0);
        vector<int> windowCount(128, 0);

        int requiredUnique = 0;

        for (char c : t) {
            if (targetCount[c] == 0) {
                requiredUnique++;
            }
            targetCount[c]++;
        }

        int left = 0, formedUnique = 0, minLength = INT_MAX, startIndex = 0;
        for (int right = 0; right < s.size(); right++) {
            char rightChar = s[right];
            windowCount[rightChar]++;

            if (targetCount[rightChar] > 0
                && windowCount[rightChar] == targetCount[rightChar]) {
                formedUnique++;
            }

            while (left <= right && formedUnique == requiredUnique) {
                char leftChar = s[left];
                if (right - left + 1 < minLength) {
                    minLength  = right - left + 1;
                    startIndex = left;
                }

                windowCount[leftChar]--;

                if (targetCount[leftChar] > 0
                    && windowCount[leftChar] < targetCount[leftChar]) {
                    formedUnique--;
                }

                left++;
            }
        }

        return ((minLength == INT_MAX) ? "" : s.substr(startIndex, minLength));
    }
};

int main() {
}
