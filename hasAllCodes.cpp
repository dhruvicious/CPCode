#include <string>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();

        if (n - k + 1 < (1 << k)) return false;

        unordered_set<string> seen;
        for (int i = 0; i <= n - k; i++) {
            string sub = s.substr(i, k);
            seen.insert(sub);

            if (seen.size() == (1 << k)) return true;
        }

        return (seen.size() == (1 << k));
    }
};
