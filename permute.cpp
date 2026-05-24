#include <algorithm>
#include <cstddef>
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findSubstringTheInefficientWay(string          s,
                                               vector<string>& words) {
        vector<int> res;

        sort(words.begin(), words.end());
        unordered_set<string> permute;

        do {
            string concat = "";
            for (const string& word : words) concat += word;
            permute.insert(concat);
        } while (next_permutation(words.begin(), words.end()));

        for (const string& p : permute) {
            size_t pos = s.find(p);
            while (pos != string::npos) {
                res.push_back(pos);
                pos = s.find(p, pos + 1);
            }
        }

        return res;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int         wordLen = words[0].size();
        int         wndoLen = wordLen * words.size();
        int         n       = s.size();

        vector<string> sortedWords = words;
        sort(sortedWords.begin(), sortedWords.end());

        for (int i = 0; i + wndoLen <= n; i++) {
            vector<string> chunks;
            for (int j = i; j < i + wndoLen; j += wordLen) {
                chunks.push_back(s.substr(j, wordLen));
            }
            sort(chunks.begin(), chunks.end());
            if (chunks == sortedWords) {
                res.push_back(i);
            }
        }

        return res;
    }

    vector<int> findSubstringHasherSlasher(string s, vector<string>& words) {
        vector<int> res;
        int         wordLen   = words[0].size();
        int         windowlen = wordLen * words.size();
        int         n         = s.size();

        hash<string> hasher;
        size_t       targetHash = 0;
        for (auto& w : words) targetHash += hasher(w);

        for (int i = 0; i < n - windowlen; i++) {
            size_t windowHash = 0;
            for (int j = i; i < i + windowlen; j += wordLen) {
                windowHash += hasher(s.substr(j, wordLen));
            }
            if (windowHash == targetHash) res.push_back(i);
        }
        return res;
    }
};
