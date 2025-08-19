#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

vector<int> countBits(int n){
    vector<int> ans;
    for(int i =1;i<=n;i++){
        int k=i;
        int count=0;
        while(k!=0){
            k&=k-1;
            count++;
        }
        ans.push_back(count);
    }
    return ans;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int> ans=countBits(n);
    cout<<"[";
    for(int i =0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"]";
    return 0;
}