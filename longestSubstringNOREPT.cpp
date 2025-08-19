#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p1=0, p2=0;
        int maxLength=0;
        unordered_set<int> inString;
        while(p2!=s.size()){
            if(inString.find(s[p2])!=inString.end()){
                inString.erase(s[p1]);
                p1++;
            }else{
                inString.insert(s[p2]);
                maxLength=max(maxLength, (p2-p1+1));
                p2++;
            }
        }
        return maxLength;
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

