#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top == '(') || (c == ')' && top == '(') ||
                c == ')' && top == '(') {
                    st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    getline(cin, s);
    if (isBalanced(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}