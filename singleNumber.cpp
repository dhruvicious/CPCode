#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define vi vector<int>

int singleNumber(vector<int>& nums){
    map<int, int> map;
    for(int num:nums){
        map[num]++;
    }
    for(auto a:map){
        if(a.second==1){
            return a.first;
        }else{
            continue;
        }
    }
}

int singleNumber(vi& nums){
    int result=0;
    for(int num:nums){
        result^=num;
    }
    return result;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}