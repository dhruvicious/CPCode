#include <bits/stdc++.h>
using namespace std;

int countHI(string& s, int i) {
    if (i >= (int)s.size() - 1) return 0;
    if (i + 1 < (int)s.size() && s[i] == 'h' && s[i + 1] == 'i' &&
        s[i + 2] != 't') {
        return 1 + countHI(s, i + 2);
    } else {
        return countHI(s, i + 1);
    }
}

void removeHI(const string& s, string& result, int i) {
    if (i >= (int)s.size()) return;
    if (i + 1 < (int)s.size() && s[i] == 'h' && s[i + 1] == 'i' &&
        s[i + 2] != 't') {
        removeHI(s, result, i + 2);
    } else {
        result += s[i];
        removeHI(s, result, i + 1);
    }
}

void replaceHI(const string& s, string& result, int i) {
    if (i >= (int)s.size()) return;
    if (i + 1 < (int)s.size() && s[i] == 'h' && s[i + 1] == 'i' &&
        s[i + 2] != 't') {
        result += "bye";
        replaceHI(s, result, i + 2);
    } else {
        result += s[i];
        replaceHI(s, result, i + 1);
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    string result1;
    string result2;
    cout << countHI(s, 0) << endl;
    removeHI(s, result1, 0);
    replaceHI(s, result2, 0);
    cout << result1 << endl;
    cout << result2 << endl;
    return 0;
}