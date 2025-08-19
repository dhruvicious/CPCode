#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int myAtoI(string s){
        int i =0, n=s.size();

        while(i<n && s[i]==' ') i++;

        bool isNeg=false;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            isNeg=s[i]=='-';
            i++;
        }

        int result=0;
        while(i<n && isdigit(s[i])){
            int digit=s[i]-'0';
            if(result>(INT_MAX-digit)/10){
                return isNeg?INT_MIN:INT_MAX;
            }
            result=result*10+digit;
            i++;
        }
        
        return isNeg?-result:result;
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