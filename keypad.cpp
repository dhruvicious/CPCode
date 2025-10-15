#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);∑
#define endl '\n'

class Solution {
   private:
    unordered_map<char, string> keypad = {
        {'1', "abc"}, {'2', "def"}, {'3', "ghi"}, {'4', "jkl"}, {'5', "mno"},
        {'6', "pqrs"}, {'7', "tuv"}, {'8', "wx"}, {'9', "yx"}};
    vector<string> res;

   public:
    void backtrack(string& path, string& digits, int index) {
        if (index == digits.size()) {
            res.push_back(path);
            return;
        }
        for (char c : keypad[digits[index]]) {
            path.push_back(c);
            backtrack(path, digits, index + 1);
            path.pop_back();
        }
        return;
    }

    vector<string> letterCombination(string s) {
        if (s.empty()) return {};
        string path;
        backtrack(path, s, 0);
        return res;
    }
};

int32_t main() {
    fastio
// #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    Solution s;
    string str;
    cin >> str;
    vector<string> res = s.letterCombination(str);
    for (string s : res) cout << s << " ";
    cout<<endl<<res.size()<<endl;
    return 0;
}