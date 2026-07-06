#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int         n    = s.size();
        int         left = 0;
        int         ans  = 0;

        for (int right = 0; right < n; right++) {
            count[s[right] - 'a']++;
            while (count[0] && count[1] && count[2]) {
                ans += (n - right);
                count[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};

int main() {
}
