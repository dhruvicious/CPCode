#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    const string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string addBinary(string a, string b, int base = 2) {
        vector<int> charToValue(256, -1);
        for (int i = 0; i < base; ++i) charToValue[symbols[i]] = i;

        if (a.length() < b.length()) return addBinary(b, a, base);
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;

        while (i >= 0) {
            int digit1 = charToValue[a[i]];
            int digit2 = (j >= 0) ? charToValue[b[j]] : 0;
            int sum = digit1 + digit2 + carry;
            a[i] = symbols[sum % base];
            carry = sum / base;

            i--;
            j--;
        }
        if (carry) a.insert(a.begin(), symbols[carry]);
        return a;
    }
};

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    Solution s;
    cout << s.addBinary(num1, num2);
}
