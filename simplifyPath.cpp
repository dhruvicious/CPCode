#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string simplifyPath(string path) {
        stringstream  ss(path);
        stack<string> st;
        string        token;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(token);
            }
        }

        string res;
        while (!st.empty()) {
            res += '/' + st.top();
            st.pop();
        }
        return res.empty() ? "/" : res;
    }
};

int main() {
}
