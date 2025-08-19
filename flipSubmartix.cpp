#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
                                            int top=x;
                                            int bottom=x+k-1;
                                            while(bottom>top){
                                                for(int col=y;col<y+k;col++){
                                                    swap(grid[top][col], grid[bottom][col]);
                                                }
                                                top++;
                                                bottom--;
                                            }
                                            return grid;
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