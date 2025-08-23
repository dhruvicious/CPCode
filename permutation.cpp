#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

void helper(vector<string>& res, int l, int r, string& s){
    if(l==r){
        res.push_back(s);
        return;
    }

    for(int i = l; i<=r;i++){
        swap(s[i], s[l]);
        helper(res, l+1, r, s);
        swap(s[i], s[l]);
    }
}

void helperINT(vector<vector<int>>& res, int l, int r, vector<int>& nums){
    if(l==r){
        res.push_back(nums);
        return;
    }

    for(int i =l;i<=r;i++){
        swap(nums[i], nums[l]);
        helperINT(res, l+1, r, nums);
        swap(nums[i], nums[l]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    helperINT(res, 0, nums.size()-1, nums);
    return res;        
}

vector<string> stringPermutation(string s){
    vector<string> res;
    helper(res, 0, s.size()-1, s);
    return res;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin,s);
    vector<string> res=stringPermutation(s);
    cout<<'[';
    for(string comb: res){
        cout<<comb<<" ";
    }
    cout<<']';
    return 0;
}