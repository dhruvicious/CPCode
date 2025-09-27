#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        long long num = llabs(numerator), den = llabs(denominator);

        result += to_string(num / den);
        long long remainder = num % den;

        if (remainder == 0) return result;
        result += ".";

        unordered_map<long long, int> seen;
        while (remainder != 0) {
            if (seen.count(remainder)) {
                result.insert(seen[remainder], "()");
                result += ")";
                break;
            }
            seen[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}