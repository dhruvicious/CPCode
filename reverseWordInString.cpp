#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);

        string word, retString;

        while (getline(ss, word, ' ')) {
            if (!word.empty()) words.push_back(word);
        }

        for (int i = words.size() - 1; i >= 0; i--) {
            retString += words[i];
            if (i > 0) retString += ' ';
        }
        return retString;
    }

    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0;

        // remove leading spaces
        while (i < n && s[i] == ' ') i++;
        while (i < n) {
            if (s[i] != ' ') {
                s[j++] = s[i++];
            } else {
                s[j++] = ' ';
                // reduce sapces betweeen word to a single space
                while (i < n && s[i] == ' ') i++;
            }
        }
        // remove trailing spaces
        if (j > 0 && s[j - 1] == ' ') j--;

        s.resize(j);

        reverse(s.begin(), s.end());

        int start = 0;
        for (int end = 0; end <= s.length(); end++) {
            if (end == s.length() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
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