#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char, int> freq;
    int oddcount = 0;
    char oddchar ='\0';
    for (char c : s) freq[c]++;
    for (auto it : freq) {
        if (it.second % 2 != 0) {
            oddcount++;
            oddchar = it.first;
        }
    }
    if (oddcount > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    string l = "", m = "", r = "";
    for (auto it : freq) {
        if (it.second % 2 != 0) {
            m.append(it.second, it.first);
        } else {
            l.append(it.second / 2, it.first);
        }
    }
    r = l;
    reverse(r.begin(), r.end());
    cout << l + m + r << endl;
    return 0;
}
