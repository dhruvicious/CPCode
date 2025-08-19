#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        int n=nums.size();
        set<vector<int>> st;

        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                set<long long> hashSet;
                for(int k =j+1;k<n;k++){
                    long long sum=nums[i]+nums[j]+nums[k];
                    long long fourth=target-sum;
                    if(hashSet.find(fourth)==hashSet.end()){
                        vector<int> temp={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
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
