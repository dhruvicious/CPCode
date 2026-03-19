#include <functional>
#include <queue>
#include <ranges>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
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

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums) freq[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto& f : freq) {
            pq.push({f.second, f.first});

            if (pq.size() > k) pq.pop();
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    string encode(vector<string>& strs) {
        string encoded;
        for (string s : strs) {
            encoded.append(s);
            encoded.append("#");
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> tokens;
        string token;
        stringstream ss(s);

        // Extract substrings separated by the delimiter
        while (getline(ss, token, '#')) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

int main() {
    return 0;
}
