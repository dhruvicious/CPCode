#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    string s;
    int k;

    bool isKRepeatedSubsequence(const string& seq) {
        int i = 0, j = 0, count = 0;
        while (i < s.size()) {
            if (s[i] == seq[j]) {
                j++;
                if (j == seq.size()) {
                    j = 0;
                    count++;
                    if (count == k) return true;
                }
            }
            i++;
        }
        return false;
    }

    void generateCandidates(string curr, vector<char>& chars, int maxLen, vector<string>& candidates) {
        if (curr.size() > maxLen) return;
        if (!curr.empty()) candidates.push_back(curr);
        for (char c : chars) {
            generateCandidates(curr + c, chars, maxLen, candidates);
        }
    }

    string longestSubsequenceRepeatedK(string _s, int _k) {
        s = _s;
        k = _k;

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        vector<char> usable;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (freq[c] >= k) usable.push_back(c);
        }

        vector<string> candidates;
        generateCandidates("", usable, s.size() / k, candidates);

        sort(candidates.begin(), candidates.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) return a.size() > b.size();
            return a > b;
        });

        for (const string& cand : candidates) {
            if (isKRepeatedSubsequence(cand)) return cand;
        }

        return "";
    }
};

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}