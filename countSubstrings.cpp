#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

int countSubstring(string s){
    if(s.empty() || s.size()==1) return 1;
    
}

int expandAroundMiddle(string s, int start, int end) {
    while (start >= 0 && end < s.size() && s[start] == s[end]) {
        start--;
        end++;
    }
    return end-start-1;
}

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}