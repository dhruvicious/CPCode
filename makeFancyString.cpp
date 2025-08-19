#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    string makeFancyString(string s){
        string retStr="";
        for(char c: s){
            if(retStr.size()<2 || !(c==retStr[retStr.size()-1] && c==retStr[retStr.size()-2])){
                retStr.push_back(c);
            }
        }
        return retStr;
    }
};

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}