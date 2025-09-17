#include <bits/stdc++.h>
using namespace std;

int countSubsequences(string& s, int i) {
    if (i == s.size()) return 1;
    return countSubsequences(s, i + 1) + countSubsequences(s, i + 1);
}

void printSubSequences(string& s, int i, string curr) {
    if (s.size() == i) {
        cout << curr << " ";
        return;
    }
    printSubSequences(s, i + 1, curr);
    printSubSequences(s, i + 1, curr += s[i]);
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    printSubSequences(s, 0, "");
    cout << endl << countSubsequences(s, 0) << endl;
    return 0;
}