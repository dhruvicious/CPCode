#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution{
public:
    void printArray(vector<vector<int>> arr){
        for(int i =0;i<arr.size();i++){
            for(int j =0;j<arr[0].size();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void rotate(vector<vector<int>> &matrix){
        a
    }
};

int32_t main()
{
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    vector<vector<int>> martix={{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(martix);
    return 0;
}