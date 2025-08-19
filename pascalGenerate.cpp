#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> pascalVals;
        for(int i =0;i<numRows;i++){
            vector<int> currRow;
            currRow[0]=1;
            for(int j=1;j<i+1;j++){
                currRow[j]=(long long)currRow[j-1]*(i+j-1)/j;
            }
            pascalVals.push_back(currRow);
        }
        return pascalVals;
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