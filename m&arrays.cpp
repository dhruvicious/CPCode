#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    unordered_map<int, string> map = {
        {'0', "abc"},  {'1', "def"}, {'2', "ghi"}, {'3', "jkl"}, {'4', "mno"},
        {'5', "pqrs"}, {'6', "tuv"}, {'7', "wx"},  {'8', "yx"},  {'9', "yx"}};
    vector<string> res;

   public:
    void backtrack(string& path, string& s, int i) {
        if (i == s.size()) {
            res.push_back(path);
            return;
        }
        for (char c : map[s[i]]) {
            path.push_back(c);
            backtrack(path, s, i + 1);
            path.pop_back();
        }
    }

    vector<string> comb(string& s) {
        if (s.empty()) return {};
        string path;
        backtrack(path, s, 0);
        return res;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution ss;
    string s;
    getline(cin, s);
    vector<string> ans = ss.comb(s);
    for (string str : ans) {
        cout << str << "\n";
    }
    return 0;
}