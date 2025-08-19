#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

char MaxFreqChar(const string& s) {
    unordered_map<char, int> freqMap;
    for (char c : s) freqMap[c]++;
    int globalMaxFreq = INT_MIN;
    char maxChar = ' ';
    for (auto& p : freqMap) {
        char c = p.first;
        int f = p.second;
        maxChar = (f > globalMaxFreq) ? c : maxChar;
        globalMaxFreq = max(globalMaxFreq, f);
    }
    return maxChar;
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    getline(cin, s);
    cout << MaxFreqChar(s);
    return 0;
}