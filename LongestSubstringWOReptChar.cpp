#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    int p1=0;
    int p2=0;
    set<char> inString;
    int maxLength=0;
    while(p2!=s.length()){
        if(inString.find(s[p2])==inString.end()){
            inString.insert(s[p2]);
            maxLength = max(maxLength, (p2-p1+1));
            p2++;
        }else{
            inString.erase(s[p1]);
            p1++;
        }
    }
    return maxLength;
}

int main() {
    
    return 0;
}