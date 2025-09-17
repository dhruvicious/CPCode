#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

// int countTwins(string s){
//     int left=0;
//     int right=left+2;
//     int twinCount=0;
//     while(right<s.size()){
//         int mid=left+(right-left)/2;
//         if(s[right]==s[left] && s[mid]!=right){
//             twinCount++;
//         }
//         right++;
//         left++;
//     }
//     return twinCount;
// }


int countTwins(const string& s, int left=0){
    int right=left+2;
    if(right>=s.size()) return 0;

    int mid = left+(right-left)/2;
    int count=0;
    if (s[right] == s[left] && s[mid] != right) {
        count = 1;
    }

    return count + countTwins(s, left + 1);
}


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin, s);

    cout<<countTwins(s);
    return 0;
}