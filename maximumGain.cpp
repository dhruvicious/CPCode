#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int maximumGain(string s, int x, int y){
        auto removeSubstr=[](string& s, char a, char b, int val ) -> pair<string, int>{
            stack<char> st;
            int score=0;
            for(char ch:s){
                if(!st.empty() && st.top() == a && ch==b){
                    st.pop();
                    score+=val;
                }else{
                    st.push(ch);
                }
            }
            string rem;
            while(!st.empty()){
                rem+=st.top();
                st.pop();
            }
            reverse(rem.begin(), rem.end());
            return {rem, score};
        };

        int total=0;
        if(x>y){
            auto [st1, sc1] =removeSubstr(s, 'a', 'b',x);
            auto [st2, sc2] =removeSubstr(st1, 'b', 'a',y);
            total=sc1+sc2;
        }
        else{
            auto [st1, sc1]=removeSubstr(s, 'b', 'a', y);
            auto [st2, sc2]=removeSubstr(st1, 'a', 'b', x);
            total=sc1+sc2;
        }
        return total;
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