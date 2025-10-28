#include <bits/stdc++.h>
using namespace std;

void norm(string& s) {
    stringstream ss(s);
    string token;
    string result;
    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            result += "0 ";
        } else {
            result += token + " ";
        }
    }
    s = result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    norm(s1);
    norm(s2);

    if (s1 == s2) {
        cout << true;
    } else {
        cout << false;
    }
    return 0;
}