#include <bits/stdc++.h>
using namespace std;

void backtrack(string& s, int i, string curr, vector<string>& result) {
    int n = s.size();

    if (i == n) {
        result.push_back(curr);
        return;
    }
    if (s[i] != '0') {
        int od = s[i] - '0';
        char letter = 'A' + od - 1;
        backtrack(s, i + 1, curr + letter, result);
    }
    if (i + 1 < n) {
        int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (twoDigit >= 10 && twoDigit <= 26) {
            char letter = 'A' + twoDigit - 1;
            backtrack(s, i + 2, curr + letter, result);
        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string digits;
    cin >> digits;

    vector<string> result;
    backtrack(digits, 0, "", result);

    for (const string& s : result) cout << s << endl;

    return 0;
}