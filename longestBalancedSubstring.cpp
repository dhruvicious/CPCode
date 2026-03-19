#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestBalanced1(string s) {
        int n = s.size();
        int res = 0;

        vector<int> freqCount(n, 0);
        for (int i = 0; i < n; i++) {
            freqCount.clear();
            for (int j = i; j < n; j++) {
                bool flag = true;
                int c = s[j] - 'a';
                freqCount[c]++;
                for (auto x : freqCount) {
                    if (x > 0 && x != freqCount[c]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }

    int longestBalanced2(string s) {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        unordered_map<long long, int> m;
        m[0] = -1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                a++;
            else if (s[i] == 'b')
                b++;
            else
                c++;

            int x = a - b;
            int y = a - c;
            long long key = ((long long) x << 32 | (unsigned int) y);

            if (m.find(key) != m.end()) {
                res = max(res, i - m[key]);
            } else {
                m[key] = i;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
