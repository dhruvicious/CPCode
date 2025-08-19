#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    string largestGoodInteger(string num){
        int n = num.size();
        string maxGood="";
        int start=0;

        while(start+2<n){
            if(num[start]==num[start+1] && num[start]==num[start+2]){
                string candidate=num.substr(start, 3);
                if(candidate>maxGood) maxGood=candidate;
                start+=2;
            }else{
                start++;
            }
        }
        return maxGood;
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