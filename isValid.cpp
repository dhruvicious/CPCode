#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3) return false;
        
        bool hasVowel=false, hasConsonant=false;
        for(char c:word){
            if(!isalnum(c)) return false;

            if(isalpha(c)){
                char lower=tolower(c);
                if(lower=='a' || lower=='e' || lower=='i' || lower=='o' || lower=='u' ) hasVowel=true;
                else hasConsonant=true;
            }
        }
        return hasVowel && hasConsonant;
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