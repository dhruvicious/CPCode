#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

constexpr int MAGIC_NUMBER = 0x20;

void toLowerCase(string& s) {
    for (char& c : s) {
        c = static_cast<char>(static_cast<unsigned char>(c) ^ ((c >= 'A' && c <= 'Z') ? MAGIC_NUMBER : 0));
    }
}

void toUpperCase(string& s) {
    for (char& c : s) {
        c = static_cast<char>(static_cast<unsigned char>(c) ^ ((c >= 'a' && c <= 'z') ? MAGIC_NUMBER : 0));
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    toLowerCase(s);
    cout << s << '\n';
    toUpperCase(s);
    cout << s << '\n';
}
