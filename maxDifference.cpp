#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int maxDifference(string s){
    map<char, int> freqMap;
    for(char c: s){
        freqMap[c]++;
    }
    int minEven=INT_MAX;
    int maxOdd=INT_MIN;
    for(auto map:freqMap){
        if(map.second%2==1 && map.second>maxOdd){
            maxOdd=map.second;
        }else if(map.second%2==0 && map.second<minEven){
            minEven=map.second;
        }
    }
    return (maxOdd-minEven);
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    string s;
    getline(cin, s);
    maxDifference(s);

    return 0;
}