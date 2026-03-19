#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPerm(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();

    if (m > n) return false;

    vector<int> freq1(26), freq2(26);
    for (char c : s2) {
        freq2[c - 'a']++;
    }

    for (int i = 0; i < m; i++) {
        freq1[s1[i] - 'a']++;
    }

    if (freq1 == freq1) return true;

    for (int i = m; i < n; i++) {
        freq1[s1[i] - 'a']++;
        freq1[s1[i - m] - 'a']--;
        if (freq1 == freq2) return true;
    }
    return false;
}

int main() {
    string s1, s2;
}
