#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    void backtrack(int start, int end, vector<string>& ans, string curr,
                   int n) {
        if (start > n || end > n) return;
        if (start == n && end == n) {
            ans.push_back(curr);
            return;
        }
        if (start < n) {
            backtrack(start + 1, end, ans, curr + '(', n);
        }
        if (end < start) {
            backtrack(start, end + 1, ans, curr + ')', n);
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> generatedParenthesis;
        string         curr;
        backtrack(0, 0, generatedParenthesis, curr, n);
        return generatedParenthesis;
    }
};

int main() {
}
