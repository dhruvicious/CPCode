#include <bits/stdc++.h>
using namespace std;

void generateParanthesis(int n, int i, string& s);
bool validParanthesis(string &s);


bool validParanthesis(string &s){
    
}

void generateParanthesis(int n, int i, string& s, int &openCount, int &closeCount) {
    if (i == 2 * n) {
        cout << s;
    }
    s.push_back('(');
    generateParanthesis(n, i + 1, s);
    s.pop_back();

    s.push_back(')');
    generateParanthesis(n,i+1, s);
    s.pop_back();
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    return 0;
}