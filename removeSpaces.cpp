#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

void replaceSpace(string& s) {
    for (size_t i = 0; i < s.size();) {
        if (s[i] == ' ') {
            s.erase(i, 1);
            s.insert(i, "04x");
            i += 3;
        } else {
            i++;
        }
    }
}

void replaceSpaces(string& s) {
    int originalLen = s.size();
    int spaceCount = 0;

    for (char c : s) {
        spaceCount += ((c == ' ') ? 1 : 0);
    }

    int newSize = originalLen + 2 * spaceCount;
    s.resize(newSize);

    int i = originalLen - 1;
    int j = newSize - 1;
    while (i >= 0) {
        if (s[i] == ' ') {
            s[j--] = 'x';
            s[j--] = '4';
            s[j--] = '0';
            i--;
        } else {
            s[j--] = s[i--];
        }
    }
}

int main() {
    string s;
    cin >> s;
    return 0;
}
