#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int getLength(vector<int>& nums) {
        int n      = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> freqCount;

            for (int j = i; j < n; j++) {
                int val = nums[j];

                int oldFreq = freq[val];
                int newFreq = oldFreq + 1;

                freq[val] = newFreq;

                if (oldFreq > 0) {
                    freqCount[oldFreq]--;
                    if (freqCount[oldFreq] == 0) {
                        freqCount.erase(oldFreq);
                    }
                }
                freqCount[newFreq]++;

                int distinctEl = freq.size();
                int uniqueFreq = freqCount.size();

                if (distinctEl == 1) {
                    maxLen = max(maxLen, j - i + 1);
                } else if (uniqueFreq == 2) {
                    auto it = freqCount.begin();
                    int  f1 = it->first;
                    int  f2 = (++it)->first;

                    if (f1 == 2 * f2 || f2 == 2 * f1) {
                        maxLen = max(maxLen, j - i + 1);
                    }
                }
            }
        }
        return maxLen;
    }
};

int main() {
}
