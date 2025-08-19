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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows=matrix.size();
        int numCols=matrix[0].size();

        int top=0, down=numRows-1;
        int validRow=-1;

        while(top<=down){
            int mid=top+(down-top)/2;
            if(matrix[mid][0]<=target && matrix[mid][numCols-1]>=target){
                validRow=mid;
                break;
            }else if(matrix[mid][0]>target){
                down=mid+1;
            }else{
                top=mid;
            }
        }
        if(validRow==-1){
            return false;
        }

        int left=0, right=numCols-1;
        int validCol=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            
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