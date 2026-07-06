#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (const string& s : strs) {
            vector<int> freq(26, 0);
            for (char c : s) freq[c - 'a']++;
            string key;

            for (int count : freq) {
                key += '#';
                key += to_string(count);
            }

            anagrams[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& entry : anagrams) {
            res.push_back(entry.second);
        }
        return res;
    }
};

int main() {
}
