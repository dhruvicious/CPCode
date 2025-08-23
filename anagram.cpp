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
    // single pass but O(n*log(n)) solution
    bool isAnagram1(string s, string t) {
        if (s.length() != t.length()) return false;

        multiset<char> ms(s.begin(), s.end());

        for (char c : t) {
            auto it = ms.find(c);
            if (it == ms.end()) return false;
            ms.erase(it);
        }

        return ms.empty();
    }
    // two pass +const work O(n) solution
    bool isAnagram2(string s, string t) {
        if (s.length() != t.length()) return false;

        int count[26] = {0};

        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;

        for (int i : count)
            if (i != 0) return false;

        return true;
    }
    // single pass + const work O(n) solution
    bool isAnagram3(string s, string t) {
        if (s.length() != t.length()) return false;

        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i : count)
            if (i != 0) return false;

        return true;
    }
    // single pass legendary solution
    bool isAnagram4(string s, string t) {
        if (s.length() != t.length()) return false;
        int count[26] = {0};
        int unmatched = 0;

        for (int i = 0; i < s.length(); i++) {
            int si = s[i] - 'a';
            int ti = t[i] - 'a';

            if (count[si] == 0) unmatched++;
            count[si]++;

            count[ti]--;
            if (count[ti] == 0) unmatched--;
        }
        return unmatched == 0;
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