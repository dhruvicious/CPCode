#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   private:
    unordered_map<char, string> mapKeys = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    vector<string> res;

    void backtrack(string& currAns, int index, string& digits) {
        if (index == digits.size()) {
            res.push_back(currAns);
            return;
        }

        for (char c : mapKeys[digits[index]]) {
            currAns.push_back(c);
            backtrack(currAns, index + 1, digits);
            currAns.pop_back();
        }
    }
    
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string path;
        backtrack(path, 0, digits);
        return res;
    }
};

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}