#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   private:
    vector<vector<int>> res;

    void backtrack(int start, int k, int n, vector<int>& subres){
        if(n==0 && k==0){
            res.push_back(subres);
            return;
        }
        if (k == 0 || n <= 0) return;
        for(int i =start; i<9;i++){
            subres.push_back(i);
            backtrack(i+1, k-1, n-i, subres);
            subres.pop_back();
        }
    }
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subres(k);
        backtrack(1, k, n, subres);
        return res;
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