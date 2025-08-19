#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'



int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin>>s;

    int oddSum=0, evenSum=0;
    for(int i=1;i<=s.size();i++){
        int digit=s[i-1]-'0';
        if(i%2==0){
            evenSum+=digit;
        }else{
            oddSum+=digit;
        }
    }
    cout<<oddSum<<endl;
    cout<<evenSum<<endl;

    return 0;
}