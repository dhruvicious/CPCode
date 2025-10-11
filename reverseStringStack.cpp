#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin>>s;
    stack<char> st;
    for(char c: s){
        st.push(c);
    }
    s= "";
    while(!st.empty()){
        s.push_back(st.top());
        st.pop();
    }
    cout<<s;
    return 0;
}