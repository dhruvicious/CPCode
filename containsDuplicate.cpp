#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<char> freqs(26);

        for (char& c : s) freqs[c - 'a']++;
        for (char& c : t) freqs[c - 'a']--;

        for (int ferq : freqs) {
            if (ferq != 0) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
