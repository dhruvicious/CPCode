#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> groups;
        for(int i=0;i<word.size();){
            int j=i;
            while(j<word.size() && word[j]==word[i]){
                j++;
            }
            int length=j-i;
            if(length>1) groups.push_back(length);
            i=j;
        }
        if(groups.empty()) return 1;
        int total=0;
        for(int length:groups) total+=length;
        return total-(groups.size()-1);
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