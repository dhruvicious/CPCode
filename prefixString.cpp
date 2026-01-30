#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int residuePrefixes(string s) {
        vector<int> freq(26, 0);
        int dCount = 0;
        int result = 0;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (freq[idx] == 0) {
                dCount++;
            }
            freq[idx]++;
            int prefixLen = i + 1;
            if (dCount == prefixLen % 3) {
                result++;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
