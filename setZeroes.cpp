#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        unordered_set<int> rows;
        unordered_set<int> cols;
        //first pass
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        //second pass
        for(int i:rows){
            for(int j=0;j<m;j++){
                matrix[i][j]=0;
            }
        }
        //third pass
        for(int j:cols){
            for(int i=0;j<n;i++){
                matrix[i][j]=0;
            }
        }

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