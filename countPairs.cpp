#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> freq;
        for (const string& s : words) {
            if (s.empty()) continue;
            int shift = s[0] - 'a';
            string nor;
            nor.reserve(s.size());

            for (char c : s) {
                char normalizedChar = (c - 'a' - shift + 26) % 26 + 'a';
                nor.push_back(normalizedChar);
            }
            freq[nor]++;
        }
        long long retval = 0;
        for (const auto& entry : freq) {
            long long f = entry.second;
            retval += f * (f - 1) / 2;
        }

        return retval;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<string> vec = {"ab", "aa", "za", "aa"};
    Solution s;
    cout<<s.countPairs(vec);
    return 0;
}
