#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> chars(26, 0);
        for (char c : ransomNote) {
            chars[c - 'a']++;
        }
        for (char c : magazine) {
            chars[c - 'a']--;
        }

        for (int i : chars) {
            if (i > 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
}
