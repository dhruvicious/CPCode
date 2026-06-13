#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<int> wordSums;
        string      res;
        for (string word : words) {
            int wordSum = 0;
            for (char c : word) {
                wordSum += weights[c - 'a'];
            }
            int val = wordSum % 26;
            res += 'z' - val;
        }
        return res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<string> words   = {"abcd", "def", "xyz"};
    vector<int>    weights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7,
                              8, 7, 10, 8,  9, 6, 9, 9, 8,  3, 7, 7, 2};

    Solution s;
    cout << s.mapWordWeights(words, weights) << endl;

    return 0;
}
