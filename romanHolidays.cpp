#include <bits/stdc++.h>
using namespace std;

int processQuery(string s, int cx, int cv, int ci);
int valueOf(char c, char next);

int valueOf(char c, char next) {
    if (c == 'X') return 10;
    if (c == 'V') return 5;
    if (c == 'I') {
        if (next == 'V' || next == 'X')
            return -1;
        else
            return 1;
    }
    return 0;
}

int processQuery(string s, int cx, int cv, int ci) {
    int n = s.size();
    string t = s;
    for (int i = 0; i < n; i++) {
        if (t[i] == '?') {
            char next = (i + 1 < n ? t[i + 1] : 'X');

            if ((next == 'X' || next == 'V') && ci > 0) {
                t[i] = 'I';
                ci--;
            } else if (ci > 0) {
                t[i] = 'I';
                ci--;
            } else if (cv > 0) {
                t[i] = 'V';
                cv--;
            } else {
                t[i] = 'X';
                cx--;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char nextChar = (i + 1 < n ? t[i + 1] : 'X');
        ans += valueOf(t[i], nextChar);
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--) {
            int cx, cv, ci;
            cin >> cx >> cv >> ci;
            cout << processQuery(s, cx, cv, ci);
        }
    }
    return 0;
}