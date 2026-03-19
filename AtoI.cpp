#include <cctype>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   private:
    int buildNumber(string& s, int i, long res, int sign) {
        if (i > s.size() || !isdigit(s[i])) {
            return sign * res;
        }
        int digit = s[i] - '0';
        if (res > (LONG_MAX / 10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        long newRes = res * 10 + digit;
        if (sign == 1 && newRes > INT_MAX) return INT_MAX;
        if (sign == -1 && newRes < INT_MIN) return INT_MIN;

        return buildNumber(s, i + 1, newRes, sign);
    }

   public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while (i < n && s[i] == ' ') i++;

        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        return buildNumber(s, i, 0, sign);
    }
};

int main() {
}
