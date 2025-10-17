#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        string s;
        getline(cin, s);

        if (isPalindrome(s)) {
            cout << "0" << '\n';
            continue;
        }

        vector<int> indices;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') indices.push_back(i + 1);
        }
        cout << indices.size() << "\n";
        for (int i = 0; i < indices.size(); i++) {
            cout << indices[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}