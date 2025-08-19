#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

string compressedString2(string s){
    int n = s.size();
    if(n==0) return s;

    string compressed;
    compressed.reserve(n);

    int read=0;
    while(read<n){
        char currChar=s[read];
        int count=0;

        while(read<n && s[read]==currChar){
            read++;
            count++;
        }
        if(count==1){
            compressed.push_back(currChar);
        }else{
            compressed.push_back(currChar);
            compressed += to_string(count);
        }
    }
    return compressed;
}

int32_t main() {
    fastio
// #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    string s;
    getline(cin, s);
    cout << compressedString2(s);
    return 0;
}