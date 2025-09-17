#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);


void permute(string& s, int l, int r, set<string>& result){
    if(l==r) {
        result.insert(s);
        return;
    }
    for(int i =l;i<r;i++){
        swap(s[i], s[l]);
        permute(s, l+1,r, result);
        swap(s[l], s[i]);
    }
}

int32_t main() {
    fastio
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    string s;
    cin>>s;
    set<string> arr;
    permute(s, 0, s.length()-1, arr);

    for(string word: arr){
        if(word<s) cout<<word<<endl;
    }
    
    return 0;
}