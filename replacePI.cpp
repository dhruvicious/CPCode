#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

void replacePI(const string &s, string &result, int i) {
    if (i >= (int)s.size()) return;
    
    if(i+1<(int)s.size() && s[i]=='p' && s[i+1]=='i'){
        result+="3.14";
        replacePI(s, result, i+2);
    }else{
        result+=s[i];
        replacePI(s, result, i+1);
    }
}

// string replacePI(const string &s) {
//     string result;
//     int n = s.size();
//     for (int i = 0; i < n;) {
//         if (i + 1 < n && s[i] == 'p' && s[i + 1] == 'i') {
//             result += "3.14";
//             i += 2;
//         } else {
//             result += s[i];
//             i++;
//         }
//     }
//     return result;
// }

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        string result="";
        replacePI(s, result, 0);
        cout<<result<<'\n';
    }
    return 0;
}