#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if (c == ')' && st.top() == '(') {
                    st.pop();
                    continue;
                } else if (c == '}' && st.top() == '{') {
                    st.pop();
                    continue;
                } else if (c == ']' && st.top() == '[') {
                    st.pop();
                    continue;
                } else {
                    return false;
                }
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};

int main() {
}
