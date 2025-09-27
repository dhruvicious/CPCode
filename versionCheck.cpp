#include <bits/stdc++.h>
using namespace std;

vector<string> splitString(const string &s, char c) {
    vector<string> arr;
    string curr = "";
    for (char st : s) {
        if (st == c) {
            arr.push_back(curr);
            curr = "";
        } else {
            curr += st;
        }
    }
    arr.push_back(curr);
    return arr;
}

int compareVersion(string version1, string version2) {
    vector<string> v1 = splitString(version1, '.');
    vector<string> v2 = splitString(version2, '.');

    int n = max(v1.size(), v2.size());
    for (int i = 0; i < n; i++) {
        int rev1 = i<v1.size()? stoi(v1[i]): 0;
        int rev2 = i<v2.size()? stoi(v2[i]): 0;

        if(rev1>rev2) return 1;
        if(rev2>rev1) return -1;
    }
    return 0;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}