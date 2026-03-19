#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> sumDigits(vector<int>& n, vector<int>& m) {
    int n1 = 0;
    int m1 = 0;
    for (int i = 0; i < n.size(); i++) {
        n1 = n1 * 10 + n[i];
    }
    for (int i = 0; i < n.size(); i++) {
        m1 = m1 * 10 + m[i];
    }
    int sum = m1 + n1;
    n.clear();
    while (sum > 0) {
        n.push_back(sum % 10);
        sum = sum / 10;
    }
    reverse(n.begin(), n.end());
    return n;
}

class Solution {
    vector<int> sum(vector<int>& n, vector<int>& m) {
        if (n.size() < m.size()) {
            return sum(m, n);
        
        int i = n.size() - 1;
        int j = m.size() - 1;
        int carry = 0;

        while (j >= 0) {
            int digit1 = n[i];
            int digit2 = m[i];
            int sum = digit1 + digit2 + carry;
            n[i] = sum % 10;
            carry = sum / 10;
            i--;
            j--;
        }

        while (i >= 0 && carry != 0) {
            int digit1 = n[i];
            int sum = digit1 + carry;
            n[i] = sum % 10;
            carry = sum / 10;
            i--;
        }

        if (carry != 0) {
            n.insert(n.begin(), carry);
        }

        return n;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
