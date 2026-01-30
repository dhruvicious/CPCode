#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSorted(const string& s) {
    for (size_t i = 0; i < s.size() - 1; i++) {
        if (s[i] > s[i + 1]) return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (isSorted(s)) {
            cout << "Bob\n";
            continue;
        }
        cout << "Alice\n";

        long long count0 = 0;
        for (char c : s) {
            if (c == '0') count0++;
        }

        vector<int> idx;
        idx.reserve(n);

        for (int i = 0; i < n; i++) {
            if (i < count0) {
                if (s[i] == '1') {
                    idx.push_back(i + 1);
                }
            } else {
                if (s[i] == '0') {
                    idx.push_back(i + 1);
                }
            }
        }
        cout << idx.size() << endl;
        for (size_t i = 0; i < idx.size(); i++) {
            cout << idx[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
